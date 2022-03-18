#include <linux/init.h>
#include <linux/module.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/kernel.h>
#include <linux/uaccess.h>
#include <linux/fs.h>

#define NMIN_DEV 2

static const char chardev_name[] = "vchardev";

static const struct file_operations vchar_fops {
	.owner      		= THIS_MODULE,
	.open       		= NULL,
	.release    		= NULL,
	.unlocked_ioctl = NULL,
	.read       		= NULL,
	.write      		= NULL
}

void vchardev_init(void) {
	dev_t dev;
	alloc_chrdev_region(&dev, 0, NMIN_DEV, chardev_name);

	struct cdev ts_cdev;
	void cdev_init(&ts_cdev, &fops);

	cdev_add(&ts_cdev, dev, );
	static struct class *mychardev_class = class_create(THIS_MODULE, chardev_name);

	for (int i = 0; i < NMIN_DEV; ++i) {
		cdev_init(&mychardev_data[i].cdev, &vchar_fops);		
	}
}


