#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/miscdevice.h>
#include <linux/sched.h>

static wait_queue_head_t rwq;

static ssize_t btn_read(struct file *file, char __user *buf, size_t count, loff_t *ppos){
	wait_queue_t wait;
	init_waitqueue_entry(&wait, current);
	add_wait_queue(&rwq, &wait);
	set_current_state(TASK_INTERRUPTIBLE);
	printk("read process %s %d will sleep...\n",current->comm, current->pid);
	schedule();
	set_current_state(TASK_RUNNING);
	remove_wait_queue(&rwq, &wait);
	if(signal_pending(current)){
		printk("read process %s %d.wake up by kill signal.\n", current->comm, current->pid);
	return -ERESTARTSYS;
	} else {
		printk("read process %s %d. wake up by driver.\n", current->comm, current->pid);
	}
	return count;
}
static ssize_t btn_write(struct file *file, const char __user *buf, size_t count, loff_t *ppos){
	printk("write process %s %d. will wake up read process.\n", current->comm, current->pid);
	wake_up(&rwq);
	return count;
}
static struct file_operations btn_fops = {
	.read = btn_read,
	.write = btn_write
};
static struct miscdevice btn_misc = {
	.minor = MISC_DYNAMIC_MINOR,
	.name = "mybtn",
	.fops = &btn_fops
};
static int btn_init(void){
	misc_register(&btn_misc);
	init_waitqueue_head(&rwq);
	return 0;
}
static void btn_exit(void)
{
    misc_deregister(&btn_misc);
}
module_init(btn_init);
module_exit(btn_exit);
MODULE_LICENSE("GPL");
