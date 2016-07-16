#include <linux/init.h>
#include <linux/module.h>

static int mymodule_start(void)
{
	printk(KERN_ALERT "Hello from KILLER!!!");

	return 0;
}

static void mymodule_end(void)
{
	printk(KERN_ALERT "Bye from KILLER!!!");
}

module_init(mymodule_start);
module_exit(mymodule_end);

MODULE_LICENSE("GPL");
