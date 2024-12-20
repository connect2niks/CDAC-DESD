// Creating CDEV Structure

#include <linux/init.h>
#include <linux/module.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>

dev_t dev = 0;
static struct cdev char_cdev;

// Function prototype

static int      __init char_driver_init(void);
static void     __exit char_driver_exit(void);
static int      char_open (struct inode *inode, struct file *filp);
static int      char_release(struct inode *inode, struct file *filp);
static ssize_t  char_read(struct file *filp, char __user *buf, size_t len, loff_t *off);
static ssize_t  char_write(struct file *filp,const char  *buf, size_t len, loff_t *off);


static struct file_operations fops =
{
    .owner      = THIS_MODULE,
    .read       = char_read,
    .write      = char_write,
    .open       = char_open,
    .release    = char_release,
};

// This function will be called when we open the device file
static int char_open(struct inode *inode, struct file *filp)
{
    pr_info("Driver open Function called....\n");
    return 0;
}
// This function will be called when we close the Device file

static int char_release(struct inode *inode, struct file *filp)
{
    pr_info("Driver Release Function called....\n");
    return 0;
}

// This function will be called when we read the Device file

static ssize_t char_read(struct file *filp, char __user *buf, size_t len, loff_t *off)
{
    pr_info("Driver Read Function called....\n");
    return 0;
}

// This function will be called when we write the Device file

static ssize_t char_write(struct file *filp,const char __user *buf, size_t len, loff_t *off)
{
    pr_info("Driver write Function called....\n");
    return 0;
}

// Module Init Function

static int __init char_driver_init(void)
{
    // Allocating Major number
    if((alloc_chrdev_region(&dev, 0,1, "simplechardevices")) < 0 )
    {
        pr_err("Cannot allocate major number for device\n");
        return -1;
    }

    pr_info("Major = %d, Minor = %d\n",MAJOR(dev), MINOR (dev));
    
    // Creating cdev structure 
    cdev_init(&char_cdev,&fops);

    // Adding character device to the system
    if ((cdev_add(&char_cdev,dev,1))< 0 )
    {
        pr_err("Cannot add the device to the system\n");

    }
    pr_info("Device Driver Insert....\n");
    return 0;

}

    // Module exit function 

static void __exit char_driver_exit(void)
    {
        cdev_del(&char_cdev);
        unregister_chrdev_region(dev, 1);
        pr_info("Device Driver Remove....Done!!!\n");

    }

    module_init(char_driver_init);
    module_exit(char_driver_exit);

    MODULE_LICENSE("GPL");

