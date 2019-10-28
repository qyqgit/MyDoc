#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/miscdevice.h>
#include <linux/sched.h> //等待队列相关
#include <linux/irq.h>
#include <linux/interrupt.h>
#include <linux/uaccess.h>
#include <linux/gpio.h>
#include <mach/platform.h>
#include <linux/input.h> //键值:KEY_*
#include <linux/timer.h>

//声明描述按键信息的数据结构
struct btn_event {
    int state; //状态
    int key_val; //键值
};

//声明描述按键硬件信息的数据结构
struct btn_info {
    char *name; //名称
    int gpio; //GPIO编号
    int key_val; //键值
};

//定义初始化按键的硬件信息对象
static struct btn_info btn_array[] = {
	{
		.name = "key_up",
		.gpio = PAD_GPIO_A + 28,
		.key_val = KEY_UP
	},
	{
		.name = "key_down",
		.gpio = PAD_GPIO_B + 9,
		.key_val = KEY_DOWN
	}
};

//定义定时器对象
static struct timer_list btn_timer;

//定义等待队列头对象
static wait_queue_head_t rwq;

//记录按键的信息
static struct btn_event kbtn;
static int condition = 0;//按键有操作:condition=1真
                     //按键无操作:condition=0假

//应用：struct btn_event btn; read(fd, &btn, 8);
//buf=&btn
static ssize_t btn_read(struct file *file,
                        char __user *buf,
                        size_t count,
                        loff_t *ppos)
{
    //1.直接休眠
    wait_event_interruptible(rwq, condition);
    condition = 0; //为了下一次read能够休眠

    //2.上报按键当前的状态和键值
    copy_to_user(buf, &kbtn, sizeof(kbtn));
    return count;
}

//记录按键硬件信息
static struct btn_info *pinfo;

//超时处理函数
static void btn_timer_function(unsigned long data)
{
    //1.获取按键状态和键值保存到全局变量给read用
    kbtn.state = gpio_get_value(pinfo->gpio);
    kbtn.key_val = pinfo->key_val;

    //2.唤醒读进程
    condition = 1; //为让read进程从wait_event_interruptible返回
    wake_up(&rwq);
}

//中断处理函数
static irqreturn_t button_isr(int irq, void *dev)
{
    //1.获取触发中断的按键信息
    pinfo = (struct btn_info *)dev;

    //2.删除定时器,重新修改,重新添加
    mod_timer(&btn_timer, jiffies + msecs_to_jiffies(10));
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

static int btn_init(void)
{
    int i;

    misc_register(&btn_misc);
    
    //初始化等待队列头对象
    init_waitqueue_head(&rwq);
    
    //申请GPIO资源
    //申请中断和注册中断处理函数
    for(i = 0; i < ARRAY_SIZE(btn_array); i++) {
        int irq = gpio_to_irq(btn_array[i].gpio);
        
        gpio_request(btn_array[i].gpio, btn_array[i].name);
        
        request_irq(irq, button_isr,
                IRQF_TRIGGER_FALLING|IRQF_TRIGGER_RISING,
                btn_array[i].name, &btn_array[i]);
    }
    //初始化定时器对象
    init_timer(&btn_timer);
    //指定超时处理函数
    btn_timer.function = btn_timer_function;
    return 0;
}

static void btn_exit(void)
{
    int i;

    //1.释放
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
