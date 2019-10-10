#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/gpio.h>
#include <mach/platform.h>
#include <asm/uaccess.h>

static dev_t dev;
static struct cdev led_cdev;
struct led_info{
	char *name;
	int gpio;
};

static struct led_info led_array[] = {
	{
		.name = "led1",
		.gpio = PAD_GPIO_C + 12
	},
	{
		.name = "led2",
		.gpio = PAD_GPIO_C + 7
	},
	{
		.name = "led3",
		.gpio = PAD_GPIO_C + 11
	},
	{
		.name = "led4",
		.gpio = PAD_GPIO_B + 26
	},
};
static ssize_t led_write(struct file *file,const char __user *buf,
		size_t count,loff_t *ppos){
	int i;
	char kcmd = 0;
	if(copy_from_user(&kcmd, buf, count))
		return -EFAULT;
	printk("kcmd:%d\n", kcmd);
	for(i = 0; i < ARRAY_SIZE(led_array); i++){
		if(kcmd & (1 << i))
			gpio_set_value(led_array[i].gpio, 0);
		else
			gpio_set_value(led_array[i].gpio, 1);
	}
	return count;
}
static ssize_t led_read(struct file *file,char __user *buf,size_t count, loff_t *ppos){
	int i;
	char kcmd = 0;
	for(i = 0; i < ARRAY_SIZE(led_array); i++){
		if(gpio_get_value(led_array[i].gpio))
			kcmd &= ~(1 << i);
		else
			kcmd |= (1 << i);
	}
	printk("kcmd:%d\n", kcmd);
	if(copy_to_user(buf, &kcmd, count))
		return -EFAULT;
	return count;
}
static struct file_operations led_fops = {
	.write = led_write,
	.read = led_read
};

static int led_init(void){
	int i;
	for(i = 0; i < ARRAY_SIZE(led_array); i++){
		gpio_request(led_array[i].gpio, led_array[i].name);
		gpio_direction_output(led_array[i].gpio, 1);
	}
	alloc_chrdev_region(&dev, 0, 1, "tarena");
	cdev_init(&led_cdev, &led_fops);
	cdev_add(&led_cdev, dev, 1);
	return 0;
}
static void led_exit(void){
	int i;
	cdev_del(&led_cdev);
	unregister_chrdev_region(dev, 1);
	for(i = 0; i < ARRAY_SIZE(led_array); i++){
		gpio_set_value(led_array[i].gpio, 1);
		gpio_free(led_array[i].gpio);
	}
}

module_init(led_init);
module_exit(led_exit);
MODULE_LICENSE("GPL");

