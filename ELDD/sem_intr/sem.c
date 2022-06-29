// Real driver application without echo and cat command.....accessing from user application storing into kernel space....

#include <linux/init.h>
#include <linux/module.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/types.h>
#include <linux/semaphore.h>   //kmalloc()
#include <linux/uaccess.h>  //copy_to/from_user()

dev_t dev_num = 0;

struct cdev *my_dev;
struct semaphore my_sema;
unsigned int op_result;

// Function prototype

static int      __init my_sema_init(void);
static void     __exit my_sema_exit(void);
static int      my_open (struct inode *inode, struct file *file);
static int      my_close(struct inode *inode, struct file *file);
static ssize_t  app_read(struct file *file, char __user *buf, size_t len, loff_t *off);
static ssize_t  app_write(struct file *file,const char  *buf, size_t len, loff_t *off);

// file operations structure

static struct file_operations fops =
{
    .owner      = THIS_MODULE,
    .read       = app_read,
    .write      = app_write,
    .open       = my_open,
    .release    = my_close,
};

// This function will be called when we open the device file
static int my_open(struct inode *inode, struct file *file)
{
    pr_info("Driver open Function called....\n");
    return 0;
}
// This function will be called when we close the Device file

static int my_close(struct inode *inode, struct file *file)
{
    pr_info("Driver Release Function called....\n");
    return 0;
}

// This function will be called when we read the Device file

static ssize_t app_read(struct file *file, char __user *buf, size_t len, loff_t *off)
{
    printk("\n In read functionality\n");
    
    // copy the data from the kernel space to the user space
    if(copy_to_user((char *)buf,&op_result, sizeof(op_result)) == 0)
    {
        printk("\n Success in reading data from kernel to user\n");
        printk("\n Read section: the result is %d\n",op_result);
        up(&my_sema);
        return len;
    }
    else{
        printk("\nError in reading data from kernel to user\n");
        return -1;
    }
}

// This function will be called when we write the Device file

static ssize_t app_write(struct file *file,const char __user *buf, size_t len, loff_t *off)
{
    down_interruptible(&my_sema);
    printk("\n In write functionality\n");

    int kbuf[2];
    int num1,num2;
    // copy the data to kernel space from the user space
    if( copy_from_user((char *)kbuf, (char *)buf, sizeof(kbuf)) == 0)
    {
        printk("Success in write data from user to kernel\n");
        num1 = kbuf[0];
        num2 = kbuf[1];
        op_result = num1 + num2;
        printk("\nResult in write section of the driver: %d\n",op_result);
        return len;
    }
    else
    {
        printk("\n Error in writing data from user to kernel\n");
        return -1;
    }
}

// Module Init Function

static int __init my_sema_init(void)
{
    printk("\nIn initialization function\n");
    
    // Allocating Major number
    if((alloc_chrdev_region(&dev_num, 0, 3, "my_sema_driver")) < 0 )
    {
        pr_err("Cannot allocate major number for device\n");
        return -1;
    }

    pr_info("Major = %d\n",MAJOR(dev_num));
    
    my_dev = cdev_alloc();
    my_dev->ops = &fops;

    // Adding character device to the system
    if ((cdev_add(my_dev,dev_num,3))< 0 )
    {
        pr_err("Cannot add the device to the system\n");
        return -1;
    }
    sema_init(&my_sema,1);
    return 0;
}

    // Module exit function 

    static void __exit my_sema_exit(void)
    {
        printk("\nIn exit section\n");
        cdev_del(my_dev);
        printk("\nSuccess in deactivate\n");
        unregister_chrdev_region(dev_num, 3);
        pr_info("\nSuccess in deregister\n");

    }

    module_init(my_sema_init);
    module_exit(my_sema_exit);

    MODULE_LICENSE("GPL");
