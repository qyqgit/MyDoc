#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>

static dev_t dev;
static int led_init(void){
	alloc_chrdev_region(&dev, 0, 1, "tmp_led");
	printk("%s:major:%d minor:%d\n", __func__, MAJOR(dev), MINOR(dev));
	return 0;
}
static void led_exit(void){
	unregister_chrdev_region(dev, 1);
}
module_init(led_init);
module_exit(led_exit);
MODULE_LICENSE("GPL");
