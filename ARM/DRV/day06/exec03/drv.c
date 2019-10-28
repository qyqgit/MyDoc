#include <linux/init.h>
#include <linux/module.h>
#include <linux/irq.h>
#include <linux/interrupt.h>
#include <linux/gpio.h>
#include <mach/platform.h>
#include <linux/input.h> //������ȫ�����м��̵ı�׼��ֵ
						 //KEY_UP,KEY_DOWN
#include <linux/fs.h>
#include <linux/miscdevice.h>
#include <linux/uaccess.h>

//������������Ӳ����Ϣ�����ݽṹ
struct btn_resource {
	char *name;//����
	int gpio; //GPIO���
	int code; //��ֵ
};

//��������������Ϣ�����ݽṹ
struct btn_event {
	int state; //����״̬
	int code; //��ֵ
};

//�����ʼ��������Ӳ����Ϣ����
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
	//1.�����ں˻�����
	struct btn_event kbtn;

	//2.��ȡ������״̬
	kbtn.state = gpio_get_value(btn_info[0].gpio);

	//3.��ȡ�����ļ�ֵ
	kbtn.code = btn_info[0].code;

	//4.�����ں����ݵ��û�
	copy_to_user(buf, &kbtn, count);
	return count;
}
						
//�����ʼ�������ӿڶ���
static struct file_operations btn_fops = {
	.read = btn_read 
};

//�����ʼ�������豸����
static struct miscdevice btn_misc = {
	.minor = MISC_DYNAMIC_MINOR,
	.name = "mybtn",
	.fops = &btn_fops
};

static int btn_init(void)
{
	int i;

	//1.����GPIO��Դ,����Ϊ����
	for(i = 0; i < ARRAY_SIZE(btn_info); i++) {
		gpio_request(btn_info[i].gpio, btn_info[i].name);
		gpio_direction_input(btn_info[i].gpio);
	}
	//2.ע������豸
	misc_register(&btn_misc);
	return 0;
}

static void btn_exit(void)
{
	int i;

	//1.�ͷ�
	for(i = 0; i < ARRAY_SIZE(btn_info); i++) {
		gpio_free(btn_info[i].gpio);
	}
	//2.ж�ػ����豸
	misc_deregister(&btn_misc);

}

module_init(btn_init);
module_exit(btn_exit);
MODULE_LICENSE("GPL");

