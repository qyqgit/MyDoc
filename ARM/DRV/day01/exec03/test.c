#include <linux/init.h>
#include <linux/module.h>

void my_test(void)
{
    printk("%s, %s, %d\n",
            __FILE__, 
            __func__,
            __LINE__);
}

//显示导出
EXPORT_SYMBOL_GPL(my_test);

MODULE_LICENSE("GPL");
