#include <linux/init.h>
#include <linux/module.h>
//cat /proc/sys/kernel/printk
static int printkall_init(void)
{
    printk("<0>" "level 0.\n");
    printk("<1>" "level 1.\n");
    printk("<2>" "level 2.\n");
    printk("<3>" "level 3.\n");
    printk("<4>" "level 4.\n");
    printk("<5>" "level 5.\n");
    printk("<6>" "level 6.\n");
    printk("<7>" "level 7.\n");
    return 0;
}

static void printkall_exit(void)
{
    printk("<0>" "level 0.\n");
    printk("<1>" "level 1.\n");
    printk("<2>" "level 2.\n");
    printk("<3>" "level 3.\n");
    printk("<4>" "level 4.\n");
    printk("<5>" "level 5.\n");
    printk("<6>" "level 6.\n");
    printk("<7>" "level 7.\n");
}
module_init(printkall_init);
module_exit(printkall_exit);
MODULE_LICENSE("GPL");
