#include <linux/init.h>
#include <linux/module.h>

static int irq;
static char *pstring;

//insmod helloworld.ko irq=111 pstring=test
//cat /sys/module/helloworld/parameters/irq
module_param(irq, int, 0664);
module_param(pstring, charp, 0);

static int helloworld_init(void)
{
    printk("%s, irq=%d, pstring=%s.\n",
            __func__, irq, pstring);
    return 0;
}

static void helloworld_exit(void)
{
    printk("%s, irq=%d, pstring=%s.\n",
            __func__, irq, pstring);
}
module_init(helloworld_init);
module_exit(helloworld_exit);
MODULE_LICENSE("GPL");
