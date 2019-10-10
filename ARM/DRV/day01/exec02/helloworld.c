#include <linux/init.h>
#include <linux/module.h>
#include "test.h" //声明

static int helloworld_init(void)
{
    //调用
    printk("%s\n", __FUNCTION__);
    my_test();
    return 0;
}

static void helloworld_exit(void)
{
    //调用
    printk("%s\n", __FUNCTION__);
    my_test();
}
module_init(helloworld_init);
module_exit(helloworld_exit);
MODULE_LICENSE("GPL");
