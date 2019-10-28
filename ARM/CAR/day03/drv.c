#include <linux/init.h>
#include <linux/module.h>
#include <linux/platform_device.h>
#include <linux/gpio.h>
#include <linux/fs.h>
#include <linux/miscdevice.h>
#include <asm/uaccess.h>
#include <mach/platform.h>

#define	GO	0x10000001
#define	BACK	0x10000002
#define STOP	0x10000003
#define LEFT	0x10000004
#define RIGHT	0x10000005

struct moto_info{
	char *name;
	int gpio;
};
struct moto_platform_info{
	struct moto_info *pinfo;
	int count;
};
struct moto_platform_info *g_platform_info = NULL;
static long moto_ioctl(struct file *file, unsigned int cmd, unsigned long buf){
	printk("moto_ioctl_%d\n", cmd);
	switch(cmd){
		case GO:
			gpio_set_value(g_platform_info->pinfo[0].gpio, 1);
			gpio_set_value(g_platform_info->pinfo[1].gpio, 1);
			gpio_set_value(g_platform_info->pinfo[2].gpio, 0);
			gpio_set_value(g_platform_info->pinfo[5].gpio, 1);
			gpio_set_value(g_platform_info->pinfo[3].gpio, 1);
			gpio_set_value(g_platform_info->pinfo[4].gpio, 0);
			printk("go\n");
			break;
		case BACK:
			gpio_set_value(g_platform_info->pinfo[0].gpio, 1);
			gpio_set_value(g_platform_info->pinfo[1].gpio, 0);
			gpio_set_value(g_platform_info->pinfo[2].gpio, 1);
			gpio_set_value(g_platform_info->pinfo[5].gpio, 1);
			gpio_set_value(g_platform_info->pinfo[3].gpio, 0);
			gpio_set_value(g_platform_info->pinfo[4].gpio, 1);
			printk("back\n");
			break;
		case STOP:
			gpio_set_value(g_platform_info->pinfo[0].gpio, 0);
			gpio_set_value(g_platform_info->pinfo[5].gpio, 0);
			printk("stop\n");
			break;
		case LEFT:
			gpio_set_value(g_platform_info->pinfo[0].gpio, 1);
			gpio_set_value(g_platform_info->pinfo[1].gpio, 1);
			gpio_set_value(g_platform_info->pinfo[2].gpio, 0);
			gpio_set_value(g_platform_info->pinfo[5].gpio, 1);
			gpio_set_value(g_platform_info->pinfo[3].gpio, 0);
			gpio_set_value(g_platform_info->pinfo[4].gpio, 1);
			printk("left\n");
			break;
		case RIGHT:
			gpio_set_value(g_platform_info->pinfo[0].gpio, 1);
			gpio_set_value(g_platform_info->pinfo[1].gpio, 0);
			gpio_set_value(g_platform_info->pinfo[2].gpio, 1);
			gpio_set_value(g_platform_info->pinfo[5].gpio, 1);
			gpio_set_value(g_platform_info->pinfo[3].gpio, 1);
			gpio_set_value(g_platform_info->pinfo[4].gpio, 0);
			printk("right\n");
			break;
	}
	return 0;
}
static struct file_operations moto_fops={
	.unlocked_ioctl = moto_ioctl
};
struct miscdevice moto_misc={
	.name = "moto_misc_dev_file",
	.minor = MISC_DYNAMIC_MINOR,
	.fops = &moto_fops
};
static int moto_probe(struct platform_device *pdev){
	int i;
	printk("moto_probe\n");
	g_platform_info = pdev->dev.platform_data;

	gpio_direction_output(g_platform_info->pinfo[0].gpio,1);
	gpio_direction_output(g_platform_info->pinfo[1].gpio,1);
	gpio_direction_output(g_platform_info->pinfo[2].gpio,1);
	gpio_direction_output(g_platform_info->pinfo[3].gpio,1);
	gpio_direction_output(g_platform_info->pinfo[4].gpio,1);
	gpio_direction_output(g_platform_info->pinfo[5].gpio,1);

	gpio_set_value(g_platform_info->pinfo[0].gpio, 0);
	gpio_set_value(g_platform_info->pinfo[5].gpio, 0);
	for(i = 0; i < g_platform_info->count; i++){
		gpio_request(g_platform_info->pinfo[i].gpio, g_platform_info->pinfo[i].name);
		gpio_direction_output(g_platform_info->pinfo[i].gpio, 1);
	}
	misc_register(&moto_misc);
	return 0;
}
static int moto_remove(struct platform_device *pdev){
	int i;
	printk("moto_remove\n");
	g_platform_info = pdev->dev.platform_data;
	gpio_set_value(g_platform_info->pinfo[0].gpio, 0);
	gpio_set_value(g_platform_info->pinfo[5].gpio, 0);
	for(i = 0; i < g_platform_info->count; i++){
		gpio_free(g_platform_info->pinfo[i].gpio);
	}
	misc_deregister(&moto_misc);
	return 0;
}
static struct platform_driver moto_drv={
	.driver={
		.name = "moto_cmp_name"
	},
	.probe = moto_probe,
	.remove = moto_remove
};
static int moto_drv_init(void){
	platform_driver_register(&moto_drv);
	return 0;
}
static void moto_drv_exit(void){
	platform_driver_unregister(&moto_drv);
}
module_init(moto_drv_init);
module_exit(moto_drv_exit);
MODULE_LICENSE("GPL");
