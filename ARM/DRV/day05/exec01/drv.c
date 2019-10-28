#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/miscdevice.h>
#include <linux/uaccess.h>
#include <linux/gpio.h>
#include <mach/platform.h>

#define LED_RD	0x10000001
#define LED_WT	0x10000002

struct led_info {
	char *name;
	int gpio;
};

static struct led_info led_array[] = {
	{
		.name = "LED1",
		.gpio = PAD_GPIO_C + 12
	},
	{
		.name = "LED2",
		.gpio = PAD_GPIO_C + 7
	},
	{
		.name = "LED3",
		.gpio = PAD_GPIO_C + 11
	},
	{
		.name = "LED4",
		.gpio = PAD_GPIO_B + 26
	},
};

static long led_ioctl(struct file *file, 
						unsigned int cmd, 
						unsigned long buf)
{
	int i;
	char status = 0;
	switch(cmd) {
		case LED_RD:
			for(i = 0; i < ARRAY_SIZE(led_array); i++){
				if(gpio_get_value(led_array[i].gpio))
					status &= ~(1 << i);
				else
					status |= (1 << i);
			}
			printk("status:%d\n", status);
			if(copy_to_user((void*)buf, &status, sizeof(status)))
				return -EFAULT;
			break;
		case LED_WT:
			if(copy_from_user(&status, (void*)buf, sizeof(status)))
				return -EFAULT;
			printk("status:%d\n", status);
			for(i = 0; i < ARRAY_SIZE(led_array); i++){
				if(status & (1 << i))
					gpio_set_value(led_array[i].gpio, 0);
				else
					gpio_set_value(led_array[i].gpio, 1);
			}
			break;
		default:
			return -EINVAL;
	}
	return 0;
}
static struct file_operations led_fops = {
	.unlocked_ioctl = led_ioctl
};
static struct miscdevice led_misc = {
	.minor = MISC_DYNAMIC_MINOR,
	.name = "misc_led",
	.fops = &led_fops
};
static int led_init(void){
	int i;
	for(i = 0; i < ARRAY_SIZE(led_array); i++){
		gpio_request(led_array[i].gpio, led_array[i].name);
		gpio_direction_output(led_array[i].gpio, 1);
	}
	misc_register(&led_misc);
	return 0;
}
static void led_exit(void){
	int i;
	for(i = 0; i < ARRAY_SIZE(led_array); i++){
		gpio_set_value(led_array[i].gpio, 1);
		gpio_free(led_array[i].gpio);
	}
        misc_deregister(&led_misc);
}
module_init(led_init);
module_exit(led_exit);
MODULE_LICENSE("GPL");
