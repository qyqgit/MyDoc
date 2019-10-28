#include <linux/init.h>
#include <linux/module.h>
#include <linux/irq.h>
#include <linux/interrupt.h>
#include <linux/gpio.h>
#include <mach/platform.h>
#include <linux/input.h> //定义了全球所有键盘的标准键值
						 //KEY_UP,KEY_DOWN
#include <linux/fs.h>
#include <linux/miscdevice.h>
#include <linux/uaccess.h>

//声明描述按键硬件信息的数据结构
struct btn_resource {
	char *name;//名称
	int gpio; //GPIO编号
	int code; //键值
};

//声明描述按键信息的数据结构
struct btn_event {
	int state; //按键状态
	int code; //键值
};

//定义初始化按键的硬件信息对象
static struct btn_resource btn_info[] = {
	{
		.name = "KEY_UP",
		.gpio = PAD_GPIO_A + 28,
		.code = KEY_UP
	}
};

//struct btn_event btn;read(fd, &btn, 8);
//buf=&btn
static ssize_t btn_read(struct file *file,
						char __user *buf,
						size_t count,
						loff_t *ppos)
{
	//1.分配内核缓冲区
	struct btn_event kbtn;

	//2.获取按键的状态
	kbtn.state = gpio_get_value(btn_info[0].gpio);

	//3.获取按键的键值
	kbtn.code = btn_info[0].code;

	//4.拷贝内核数据到用户
	copy_to_user(buf, &kbtn, count);
	return count;
}
						
//定义初始化操作接口对象
static struct file_operations btn_fops = {
	.read = btn_read 
};

//定义初始化混杂设备对象
static struct miscdevice btn_misc = {
	.minor = MISC_DYNAMIC_MINOR,
	.name = "mybtn",
	.fops = &btn_fops
};

static int btn_init(void)
{
	int i;

	//1.申请GPIO资源,配置为输入
	for(i = 0; i < ARRAY_SIZE(btn_info); i++) {
		gpio_request(btn_info[i].gpio, btn_info[i].name);
		gpio_direction_input(btn_info[i].gpio);
	}
	//2.注册混杂设备
	misc_register(&btn_misc);
	return 0;
}

static void btn_exit(void)
{
	int i;

	//1.释放
	for(i = 0; i < ARRAY_SIZE(btn_info); i++) {
		gpio_free(btn_info[i].gpio);
	}
	//2.卸载混杂设备
	misc_deregister(&btn_misc);

}

module_init(btn_init);
module_exit(btn_exit);
MODULE_LICENSE("GPL");

