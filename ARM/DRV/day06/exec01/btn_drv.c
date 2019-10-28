#include <linux/init.h>
#include <linux/module.h>
#include <linux/irq.h>
#include <linux/interrupt.h>
#include <linux/gpio.h>
#include <mach/platform.h>

static int g_data = 0xffff;
static struct btn_info *pinfo;
struct btn_info{
	char *name;
	int gpio;
};
static struct work_struct btn_work;
 
static struct btn_info btn_array[] = {
	{
		.name = "key_up",
		.gpio = PAD_GPIO_A + 28
	},
	{
		.name = "key_down",
		.gpio = PAD_GPIO_B + 9
	}
};
static void btn_work_function(struct work_struct *work)
{
		int state;
		//1.获取按键状态
		state = gpio_get_value(pinfo->gpio);
		//2.打印
		printk("%s: key[%s]  state[%s]\n",
				__func__, pinfo->name, state ?"release":"press");
}
static irqreturn_t button_isr(int irq, void *dev){
	pinfo = (struct btn_info*)dev;
	g_data = gpio_get_value(pinfo->gpio);
	schedule_work(&btn_work);
	return IRQ_HANDLED;
}
static int btn_init(void){
	int i;
	for(i = 0; i < ARRAY_SIZE(btn_array); i++){
		int irq = gpio_to_irq(btn_array[i].gpio);
		gpio_request(btn_array[i].gpio, btn_array[i].name);
		if(request_irq(irq, button_isr, IRQF_TRIGGER_FALLING | IRQF_TRIGGER_RISING,
		btn_array[i].name, &btn_array[i]))
			return -EBUSY;
	}
	INIT_WORK(&btn_work, btn_work_function);
	return 0;
}
static void btn_exit(void){
	int i;
	for(i = 0; i < ARRAY_SIZE(btn_array); i++){
		int irq = gpio_to_irq(btn_array[i].gpio);
		gpio_free(btn_array[i].gpio);
		free_irq(irq, &btn_array[i]);
	}
}
module_init(btn_init);
module_exit(btn_exit);
MODULE_LICENSE("GPL");
