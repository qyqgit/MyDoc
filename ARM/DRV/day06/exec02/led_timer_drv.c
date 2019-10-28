#include <linux/init.h>
#include <linux/module.h>
#include <linux/irq.h>
#include <linux/interrupt.h>
#include <linux/gpio.h>
#include <mach/platform.h>
#include <linux/delay.h>

static int g_data = 2;

module_param(g_data, int, 0664);

static struct btn_info *pinfo;

struct btn_info{
	char *name;
	int gpio;
};

static struct work_struct btn_work;

static struct timer_list led_timer;

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
		if(pinfo->gpio == PAD_GPIO_A + 28)		
			g_data++;
		if(pinfo->gpio == PAD_GPIO_B + 9)
			g_data--;
		if(g_data < 1)
			g_data = 1;
}
static void led_timer_function(unsigned long data)
{
	printk("%s: g_data = %d\n", __func__, *(int *)data);
	#if 0
	//加锁
	
	//重新修改超时时间
	led_timer.expires = jiffies + 2*HZ;
	
	//重新添加定时器
	add_timer(&led_timer);
	
	//解锁
	#endif
	//开关灯:不允许用if...else,一条语句拿下
	
	//此函数会帮你互斥访问
	mod_timer(&led_timer, jiffies + g_data*HZ);
}

static irqreturn_t button_isr(int irq, void *dev){
	pinfo = (struct btn_info*)dev;
	schedule_work(&btn_work);
	return IRQ_HANDLED;
}
static int led_timer_init(void){
	int i;
	for(i = 0; i < ARRAY_SIZE(btn_array); i++){
		int irq = gpio_to_irq(btn_array[i].gpio);
		gpio_request(btn_array[i].gpio, btn_array[i].name);
		if(request_irq(irq, button_isr, IRQF_TRIGGER_FALLING | IRQF_TRIGGER_RISING,
		btn_array[i].name, &btn_array[i]))
			return -EBUSY;
	}
	INIT_WORK(&btn_work, btn_work_function);
	init_timer(&led_timer);
	led_timer.expires = jiffies + 2*HZ;
	led_timer.function = led_timer_function;
	led_timer.data = (unsigned long)&g_data;
	add_timer(&led_timer);
	printk("register timer successfully.\n");
	return 0;
}
static void led_timer_exit(void){
	int i;
	for(i = 0; i < ARRAY_SIZE(btn_array); i++){
		int irq = gpio_to_irq(btn_array[i].gpio);
		gpio_free(btn_array[i].gpio);
		free_irq(irq, &btn_array[i]);
	}
	del_timer(&led_timer);
}
module_init(led_timer_init);
module_exit(led_timer_exit);
MODULE_LICENSE("GPL");
