#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/miscdevice.h>
#include <linux/sched.h>
#include <linux/irq.h>
#include <linux/interrupt.h>
#include <linux/uaccess.h>
#include <linux/gpio.h>
#include <mach/platform.h>
#include <linux/input.h>

struct btn_event {
    int state;
    int key_val;
};

struct btn_info {
    char *name;
    int gpio;
    int code;
};
static struct btn_info btn_array[] = {
	{
		.name = "KEY_UP",
		.gpio = PAD_GPIO_A + 28,
		.code = KEY_UP
	},
	{
		.name = "KEY_DOWN",
		.gpio = PAD_GPIO_B + 9,
		.code = KEY_DOWN
	}
};

static wait_queue_head_t rwq;

static struct btn_event kbtn;

static ssize_t btn_read(struct file *file, char __user *buf, size_t count, loff_t *ppos){
	wait_queue_t wait;
	init_waitqueue_entry(&wait, current);
	add_wait_queue(&rwq, &wait);
	set_current_state(TASK_INTERRUPTIBLE);
	printk("read process %s %d will sleep...\n",current->comm, current->pid);
	schedule();
	set_current_state(TASK_RUNNING);
	remove_wait_queue(&rwq, &wait);
	if(signal_pending(current)){
		printk("read process %s %d.wake up by kill signal.\n", current->comm, current->pid);
	return -ERESTARTSYS;
	} else {
		printk("read process %s %d. wake up by driver.\n", current->comm, current->pid);
		copy_to_user(buf, &kbtn, sizeof(kbtn));
	}
	return count;
}
static irqreturn_t button_isr(int irq, void *dev)
{
    //1.获取触发中断的按键信息
    struct btn_info *pdata = (struct btn_info *)dev;

    //2.获取按键状态和键值保存到全局变量给read用
    kbtn.state = gpio_get_value(pdata->gpio);
    kbtn.key_val = pdata->code;

    //3.唤醒读进程
    wake_up(&rwq);
    return IRQ_HANDLED;
}
static struct file_operations btn_fops = {
	.owner = THIS_MODULE, //保护作用 
	.read = btn_read,
};
static struct miscdevice btn_misc = {
	.minor = MISC_DYNAMIC_MINOR,
	.name = "mybtn",
	.fops = &btn_fops
};
static int btn_init(void){
	int i;
	misc_register(&btn_misc);
	init_waitqueue_head(&rwq);
        for(i = 0; i < ARRAY_SIZE(btn_array); i++) {
            int irq = gpio_to_irq(btn_array[i].gpio);
        
            gpio_request(btn_array[i].gpio, btn_array[i].name);
        
            request_irq(irq, button_isr,
                IRQF_TRIGGER_FALLING|IRQF_TRIGGER_RISING,
                btn_array[i].name, &btn_array[i]);
        }
	return 0;
}
static void btn_exit(void)
{
    int i;
    for(i = 0; i < ARRAY_SIZE(btn_array); i++) {
        int irq = gpio_to_irq(btn_array[i].gpio);
        gpio_free(btn_array[i].gpio);
        free_irq(irq, &btn_array[i]);
    }
    misc_deregister(&btn_misc);
}
module_init(btn_init);
module_exit(btn_exit);
MODULE_LICENSE("GPL");
