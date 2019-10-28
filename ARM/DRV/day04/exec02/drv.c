#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/gpio.h>
#include <mach/platform.h>
#include <asm/uaccess.h>
#include <linux/device.h>

#define LED_ON	0x10000001
#define LED_OFF	0x10000002

static dev_t dev;
static struct cdev led_cdev;
static struct class *cls;
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
//fd0->file0->inode0->i_rdev0->主设备号A,次设备号0
//fd1->file1->inode1->i_rdev1->主设备号A,次设备号1
//fd2->file2->inode2->i_rdev2->主设备号A,次设备号2
//fd3->file3->inode3->i_rdev3->主设备号A,次设备号3
static long led_ioctl(struct file *file, 
						unsigned int cmd, 
						unsigned long buf)
{
	struct inode *inode = file->f_path.dentry->d_inode;
	int minor = MINOR(inode->i_rdev);
	switch(cmd) {
		case LED_ON:
			gpio_set_value(led_array[minor].gpio, 0);
			break;
		case LED_OFF:
			gpio_set_value(led_array[minor].gpio, 1);
			break;
		default:
			return -EINVAL;
	}
	return 0;
}
static struct file_operations led_fops = {
	.unlocked_ioctl = led_ioctl
};

static int led_init(void){
	int i;
	for(i = 0; i < ARRAY_SIZE(led_array); i++){
		gpio_request(led_array[i].gpio, led_array[i].name);
		gpio_direction_output(led_array[i].gpio, 1);
	}
	alloc_chrdev_region(&dev, 0, 4, "tarena");
	cdev_init(&led_cdev, &led_fops);
	cdev_add(&led_cdev, dev, 4);
        cls = class_create(THIS_MODULE, "tarena_cls");
    	device_create(cls, NULL, MKDEV(MAJOR(dev),0), NULL, "myled0");
	device_create(cls, NULL, MKDEV(MAJOR(dev),1), NULL, "myled1");
	device_create(cls, NULL, MKDEV(MAJOR(dev),2), NULL, "myled2");
	device_create(cls, NULL, MKDEV(MAJOR(dev),3), NULL, "myled3");
	return 0;
}
static void led_exit(void){
	int i;
	cdev_del(&led_cdev);
	unregister_chrdev_region(dev, 4);
	for(i = 0; i < ARRAY_SIZE(led_array); i++){
		gpio_set_value(led_array[i].gpio, 1);
		gpio_free(led_array[i].gpio);
	}
        device_destroy(cls, dev+0);
	device_destroy(cls, dev+1);
	device_destroy(cls, dev+2);
	device_destroy(cls, dev+3);
        class_destroy(cls);
}

module_init(led_init);
module_exit(led_exit);
MODULE_LICENSE("GPL");

