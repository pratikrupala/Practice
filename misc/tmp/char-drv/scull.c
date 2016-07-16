#include <linux/module.h>
#include <linux/fs.h>
#include <linux/slab.h>

#include "scull.h"

MODULE_AUTHOR("PRATIK RUPALA");
MODULE_LICENSE("Dual BSD/GPL");

int scull_major   = SCULL_MAJOR;
int scull_minor   = 0;
int scull_nr_devs = SCULL_NR_DEVS;
int scull_quantum = SCULL_QUANTUM;
int scull_qset    = SCULL_QSET;

module_param(scull_major, int, S_IRUGO);
module_param(scull_minor, int, S_IRUGO);
module_param(scull_nr_devs, int, S_IRUGO);
module_param(scull_quantum, int, S_IRUGO);
module_param(scull_qset, int, S_IRUGO);

struct scull_dev *scull_devices;

static void scull_trim(struct scull_dev *dev)
{
	int i, qset = dev->qset;
	struct scull_dev *dptr, *next;

	for (dptr = dev->first; dptr; dptr = next) {
		if (dptr->data) {
			for (i = 0; i < qset; i++)
				kfree(dptr->data[i]);
			kfree(dptr->data);
			dptr->data = NULL;
		}
		next = dptr->next;
		kfree(dptr);
	}
	dev->size = 0;
	dev->qset = scull_qset;
	dev->quantum = scull_quantum;
	dev->first = NULL;
}

static void scull_exit(void)
{
	dev_t dev = MKDEV(scull_major, scull_minor);

	if (scull_devices) {
		for (i = 0; i < scull_nr_devs; i++) {
			scull_trim(scull_devices + i);
			cdev_del(&scull_devices[i].cdev);
		}
		kfree(scull_devices);
	}

	/* Unregister the devices registered */
	unregister_chrdev_region(dev, scull_nr_devs);

	printk(KERN_ALERT "Bye from SCULL.\n");
}

ssize_t scull_open(struct inode *scull_inode, struct file *filp);
ssize_t scull_release(struct inode *scull_inode, struct file *filp);
ssize_t scull_read(struct file *filp, char __user *buf, size_t size,
                   loff_t *pos);
ssize_t scull_write(struct file *filp, const char __user *buf, size_t size,
                    loff_t *pos);
long scull_ioctl(struct file *filp, unsigned int i, unsigned long j);

struct file_operations scull_fops = {
	.owner            = THIS_MODULE,
	.read             = scull_read,
	.write            = scull_write,
	.unlocked_ioctl   = scull_ioctl,
	.open             = scull_open,
	.release          = scull_release,
};

static void scull_setup_cdev(struct scull_dev *dev, int index)
{
	int ret = 0;
	dev_t devno = MKDEV(scull_major, scull_minor + index);

	printk(KERN_ALERT "Inside setup cdev.\n");	

	cdev_init(&dev->cdev, &scull_fops);
	dev->cdev.owner = THIS_MODULE;
	dev->cdev.ops = &scull_fops;
	ret = cdev_add(&dev->cdev, devno, 1);

	if(ret)
		printk(KERN_ALERT "KILLER failed to add cdev.\n");
}

static int scull_init(void)
{
	int   i;
	int   ret = 0;
	dev_t dev = 0;

	printk(KERN_ALERT "Hello from SCULL.\n");

	if (scull_major) {
		dev = MKDEV(scull_major, scull_minor);
		ret = register_chrdev_region(dev, scull_nr_devs, "scull");
	} else {
		ret = alloc_chrdev_region(&dev, scull_minor, scull_nr_devs,
                                          "scull");
		scull_major = MAJOR(dev);
	}

	if (ret != 0) {
		printk(KERN_ALERT "Failed to register scull device.\n");
		return ret;
	}

	printk(KERN_ALERT "SCULL: Major:%d\n", scull_major);

	scull_devices = (struct scull_dev *) kmalloc(scull_nr_devs *
                          sizeof(struct scull_dev), GFP_KERNEL);
	if (!scull_devices) {
		printk(KERN_ALERT "Failed to allocate memory for scull \
                       devices.\n");
		ret = -ENOMEM;
		goto fail;
	}
	memset(scull_devices, 0, sizeof(struct scull_dev));

	for (i = 0; i < scull_nr_devs; i++) {
		scull_devices[i].quantum = scull_quantum;
		scull_devices[i].qset = scull_qset;
		mutex_init(&scull_devices[i].slock);
		scull_setup_cdev(&scull_devices[i], i);
	}

	return 0;

fail:
	scull_exit();
	return ret;
}

module_init(scull_init);
module_exit(scull_exit);
