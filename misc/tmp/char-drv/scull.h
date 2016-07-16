#include <linux/cdev.h>
#include <linux/mutex.h>

#ifndef SCULL_MAJOR
#define SCULL_MAJOR 0
#endif

#ifndef SCULL_NR_DEVS
#define SCULL_NR_DEVS 2
#endif

#ifndef SCULL_QUANTUM
#define SCULL_QUANTUM 5000
#endif

#ifndef SCULL_QSET
#define SCULL_QSET 10
#endif

/* Structure representing a single set of data in a device */
struct scull_qset {
	void **data;
	struct scull_qset *next;
};

/* Structure to represent a single scull device */
struct scull_dev {
	struct scull_qset *first;	/* First qset of a device */
	int quantum;			/* Size of a single quantum */
	int qset;			/* Length of an array of quantum */
	unsigned int size;		/* Current size of the device */
	struct mutex slock;		/* Semaphore to protect the device */
	struct cdev cdev;		/* Structure to register fops */
};
