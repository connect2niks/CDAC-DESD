// Creating CDEV Structure

#include <linux/init.h>
#include <linux/module.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/kernel.h>
#include <linux/timer.h>
#include <linux/jiffies.h>

//Timer Variable
#define TIMEOUT 1000    //millisecond

static struct timer_list hc_timer;
static unsigned int count = 0;

dev_t dev = 0;
static struct cdev hc_cdev;
static struct class *dev_class;

// Function prototype

static int      __init hc_driver_init(void);
static void     __exit hc_driver_exit(void);
static int      hc_open (struct inode *inode, struct file *filp);
static int      hc_release(struct inode *inode, struct file *filp);
static ssize_t  hc_read(struct file *filp, char __user *buf, size_t len, loff_t *off);
static ssize_t  hc_write(struct file *filp,const char  *buf, size_t len, loff_t *off);


static struct file_operations fops =
{
    .owner      = THIS_MODULE,
    .read       = hc_read,
    .write      = hc_write,
    .open       = hc_open,
    .release    = hc_release,
};

// Timer callback function. This will be called when timer expires
void timer_callback(struct timer_list * data)
{
    //do your timer stuff here
    pr_info("Timer callback function called [%d]\n",count++);

    /*
    Re-enable timer. Because this function will be called only first time.
    If we re-enable this will work like periodic timer.
    */
   mod_timer(&hc_timer, jiffies + msecs_to_jiffies(TIMEOUT));

}
// This function will be called when we open the device file
static int hc_open(struct inode *inode, struct file *filp)
{
    pr_info("Driver open Function called....\n");
    return 0;
}
// This function will be called when we close the Device file

static int hc_release(struct inode *inode, struct file *filp)
{
    pr_info("Driver Release Function called....\n");
    return 0;
}

// This function will be called when we read the Device file

static ssize_t hc_read(struct file *filp, char __user *buf, size_t len, loff_t *off)
{
    pr_info("Driver Read Function called....\n");
    return 0;
}

// This function will be called when we write the Device file

static ssize_t hc_write(struct file *filp,const char __user *buf, size_t len, loff_t *off)
{
    pr_info("Driver write Function called....\n");
    return 0;
}

// Module Init Function

static int __init hc_driver_init(void)
{
    // Allocating Major number
    if((alloc_chrdev_region(&dev, 0,1, "hc_dev")) < 0 )
    {
        pr_err("Cannot allocate major number for device\n");
        return -1;
    }

    pr_info("Major = %d, Minor = %d\n",MAJOR(dev), MINOR (dev));
    
    // Creating cdev structure 
    cdev_init(&hc_cdev,&fops);

    // Adding character device to the system
    if ((cdev_add(&hc_cdev,dev,1))< 0 )
    {
        pr_err("Cannot add the device to the system\n");
        goto r_class;
    }

    // Creating struct class
    if((dev_class = class_create(THIS_MODULE, "hc_class")) == NULL){
        pr_err("Cannot create the struct class\n");
        goto r_class;
    }

    //Creating device
    if((device_create(dev_class, NULL, dev, NULL, "hc_device")) == NULL){
        pr_err("Cannot create the device \n");
        goto r_device;
    }

    //setup your timer to call my_timer_callback
    timer_setup(&hc_timer, timer_callback, 0);   /*if you face some issues and using older kernel version, then you can try setup_timer API
    change callback function's argument to unsigned long instead of struct timer_list */

    //setup timer interval to based on TIMEOUT macro
    mod_timer(&hc_timer, jiffies + msecs_to_jiffies(TIMEOUT));

    pr_info("Device Driver Insert....\n");
    return 0;
r_device:
    class_destroy(dev_class);
r_class:
    unregister_chrdev_region(dev,1);
    return -1;
}

    // Module exit function 

static void __exit hc_driver_exit(void)
    {
        cdev_del(&hc_cdev);
        unregister_chrdev_region(dev, 1);
        pr_info("Device Driver Remove....Done!!!\n");

    }

    module_init(hc_driver_init);
    module_exit(hc_driver_exit);

    MODULE_LICENSE("GPL");

