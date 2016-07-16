#include <linux/init.h>
#include <linux/module.h>

static int mymod_start(void)
{
	printk(KERN_ALERT "Hello from KILLER!!!\n");
	return 0;
}

static void mymod_end(void)
{
	printk(KERN_ALERT "Bye from KILLER!!!\n");
}

module_init(mymod_start);
module_exit(mymod_end);

MODULE_LICENSE("GPL");
