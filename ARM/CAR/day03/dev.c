#include <linux/init.h>
#include <linux/platform_device.h>
#include <linux/module.h>
#include <linux/gpio.h>
#include <mach/platform.h>

struct moto_info{
	char *name;
	int gpio;
};
struct moto_platform_info{
	struct moto_info *pinfo;
	int count;
};
static struct moto_info moto_array[]={
	{
		.name = "ENA",
		.gpio = PAD_GPIO_A + 30,
	},
	{
		.name = "IN1",
		.gpio = PAD_GPIO_B + 0,
	},
	{
		.name = "IN2",
		.gpio = PAD_GPIO_B + 2,
	},
	{
		.name = "IN3",
		.gpio = PAD_GPIO_B + 4,
	},
	{
		.name = "IN4",
		.gpio = PAD_GPIO_B + 6,
	},
	{
		.name = "ENB",
		.gpio = PAD_GPIO_B + 10,
	},
};
static struct moto_platform_info moto_platform_head={
	.pinfo = moto_array,
	.count = ARRAY_SIZE(moto_array)
};
static void moto_release(struct device *dev){
}
static struct platform_device moto_dev={
	.name = "moto_cmp_name",
	.id = -1,
	.dev = {
		.platform_data = &moto_platform_head,
		.release = moto_release
	}
};
static int moto_dev_init(void){
	platform_device_register(&moto_dev);
	return 0;
}
static void moto_dev_exit(void){
	platform_device_unregister(&moto_dev);
}
module_init(moto_dev_init);
module_exit(moto_dev_exit);
MODULE_LICENSE("GPL");
