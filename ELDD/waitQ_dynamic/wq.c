// Dynamic wait queue 

#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/slab.h>   //kmalloc()
#include <linux/uaccess.h>  //copy_to/from_user()
#include <linux/kthread.h>
#include <linux/wait.h>

uint32_t read_count = 0;
uint32_t write_count = 0;
static struct task_struct *wait_thread;

dev_t dev = 0;
static struct class *dev_class;
static struct cdev wq_cdev;
wait_queue_head_t wait_queue_wq;
int wait_queue_flag = 0;

// Function prototype

static int      __init wq_driver_init(void);
static void     __exit wq_driver_exit(void);
static int      wq_open (struct inode *inode, struct file *file);
static int      wq_release(struct inode *inode, struct file *file);
static ssize_t  wq_read(struct file *filep, char __user *buf, size_t len, loff_t *off);
static ssize_t  wq_write(struct file *filep,const char  *buf, size_t len, loff_t *off);

// file operations structure

static struct file_operations fops =
{
    .owner      = THIS_MODULE,
    .read       = wq_read,
    .write      = wq_write,
    .open       = wq_open,
    .release    = wq_release,
};


// Thread Function

static int wait_function(void *unused)
{
    while (1)
    {
        pr_info("waiting for the Event....\n");
        wait_event_interruptible(wait_queue_wq, wait_queue_flag != 0);
        if (wait_queue_flag == 2)
        {
            pr_info("Event came from Exit function\n");
            return 0;
        }

        if (wait_queue_flag == 1)
        {
            pr_info("Event came from read function %d  \n",++read_count);
        }
        
        if (wait_queue_flag == 3)
        {
            pr_info("Event came from write function  %d  \n ", ++write_count);
            wait_queue_flag = 0;
        }
        wait_queue_flag = 0;
        
    }
    return 0;
    
}
// This function will be called when we open the device file
static int wq_open(struct inode *inode, struct file *file)
{
    pr_info("Driver open Function called....\n");
    return 0;
}
// This function will be called when we close the Device file

static int wq_release(struct inode *inode, struct file *file)
{
    pr_info("Driver Release Function called....\n");
    return 0;
}

// This function will be called when we read the Device file

static ssize_t wq_read(struct file *filp, char __user *buf, size_t len, loff_t *off)
{
    pr_info("Read Function\n");
    wait_queue_flag = 1;
    wake_up_interruptible(&wait_queue_wq);
    return 0;
}

// This function will be called when we write the Device file

static ssize_t wq_write(struct file *filp,const char __user *buf, size_t len, loff_t *off)
{
    pr_info("Write Function\n");
    wait_queue_flag = 3;
    wake_up_interruptible(&wait_queue_wq);
    return len;
}

// Module Init Function

static int __init wq_driver_init(void)
{
    // Allocating Major number
    if((alloc_chrdev_region(&dev, 0,1, "wq_dev")) < 0 )
    {
        pr_err("Cannot allocate major number for device\n");
        return -1;
    }

    pr_info("Major = %d, Minor = %d\n",MAJOR(dev), MINOR (dev));
    
    // Creating cdev structure 
    cdev_init(&wq_cdev,&fops);

    // Adding character device to the system
    if ((cdev_add(&wq_cdev,dev,1))< 0 )
    {
        pr_err("Cannot add the device to the system\n");
        goto r_class;
    }

    //creating struct class
    if((dev_class = class_create(THIS_MODULE, "wq_class")) == NULL)
    {
        pr_info("cannot create the struct class\n");
        goto r_class;
    }

    // creating device
    if((device_create(dev_class, NULL, dev, NULL, "wq_device")) == NULL)
    {
        pr_info("cannot create te device 1\n");
        goto r_device;
    }

    //Initialize wait queue
    init_waitqueue_head(&wait_queue_wq);

    //create the kernel thread with name 'mythread'
    wait_thread = kthread_create(wait_function, NULL, "waitthread");

    if(wait_thread)
    {
        pr_info("Thread created sucessfully\n");
        wake_up_process(wait_thread);
    }
    else
    pr_info("Thread creation failed\n");

    pr_info("Device Driver Insert....Done!!!\n");
    return 0;

r_device:
        class_destroy(dev_class);
r_class:
        unregister_chrdev_region(dev,1);
        return -1;

}        

// Module exit function 

    static void __exit wq_driver_exit(void)
    {
        wait_queue_flag = 2;
        wake_up_interruptible(&wait_queue_wq);
        device_destroy(dev_class,dev);
        class_destroy(dev_class);
        cdev_del(&wq_cdev);
        unregister_chrdev_region(dev, 1);
        pr_info("Device Driver Remove....Done!!!\n");

    }

    module_init(wq_driver_init);
    module_exit(wq_driver_exit);

    MODULE_LICENSE("GPL");

