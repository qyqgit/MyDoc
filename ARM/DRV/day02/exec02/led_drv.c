#include <linux/init.h>
#include <linux/module.h>
#include <linux/gpio.h>
#include <mach/platform.h>
struct led_resource{
	char *name;
	int gpio;
};
static struct led_resource led_info[] = {
	{
		.gpio = PAD_GPIO_C + 12,
		.name = "led1"
	},
	{
		.gpio = PAD_GPIO_C + 7,
		.name = "led2"
	}
};
static int led_init(void){
	int i;
	for(i = 0; i < ARRAY_SIZE(led_info); i++){
		gpio_request(led_info[i].gpio, led_info[i].name);
		gpio_direction_output(led_info[i].gpio, 0);
		printk("%s: open%dled.\n", __func__, i+1);
	}
	return 0;
}
static void led_exit(void){
	int i;
	for(i = 0; i < ARRAY_SIZE(led_info); i++){
		gpio_set_value(led_info[i].gpio, 1);
		gpio_free(led_info[i].gpio);
		printk("%s:close%dled.\n", __func__, i+1);
	}
}
module_init(led_init);
module_exit(led_exit);
MODULE_LICENSE("GPL");
