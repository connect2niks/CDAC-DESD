#include <linux/init.h>
#include <linux/module.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/kernel.h>

#include "ioctl.h"

#define COUNT 1
#define DEV_NAME "niks"

dev_t dev_num = 0;
static struct cdev mycdev;

static int mycdev_open(struct inode *inode, struct file *filp)
{
    pr_info("mycdev_open involked\n");
    return 0;
}

static int mycdev_release(struct inode *inode, struct file *filp)
{
    pr_info("mycdev_release involked\n");
    return 0;
}

static ssize_t mycdev_read(struct file *filp, char __user *buf, size_t len, loff_t *pos)
{
    pr_info("mycdev_read involked\n");
    return 0;
}

static ssize_t mycdev_write(struct file *filp,const char __user *buf, size_t len, loff_t *pos)
{
    pr_info("mycdev_write involked\n");
    return 0;
}

static long mycdev_ioctl(struct file *filp, unsigned int cmd, unsigned long arg)
{
    pr_info("mycdev_local involked\n");
    switch (cmd)
    {
    case CMD_1:
        pr_alert("This is CMD_1 command.\n");
        break;

    case CMD_2:
        pr_alert("This is CMD_2 command. Received arg - %d\n",arg);
        break;
    
    default:
        pr_info("Invalid Command.\n");
        break;
    }
    return 0;
}

static struct file_operations mycdev_fops = 
{
    .owner      = THIS_MODULE,
    .read       = mycdev_read,
    .write      = mycdev_write,
    .open       = mycdev_open,
    .release    = mycdev_release,
    .unlocked_ioctl = mycdev_ioctl,
};

static int __init mycdev_init(void)
{
    pr_info("mycdev init is involked");
    if((alloc_chrdev_region(&dev_num, 0, COUNT, DEV_NAME)) < 0 )
    {
        pr_err("Cannot allocate major number for device\n");
        return -1;
    }

    pr_info("Major = %d, Minor = %d\n",MAJOR(dev_num), MINOR (dev_num));

    cdev_init(&mycdev,&mycdev_fops);

    if ((cdev_add(&mycdev,dev_num,1))< 0 )
    {
        pr_err("Cannot add the device to the system\n");

    }
    pr_info("mycdev device driver loaded\n");
    return 0;

}

static void __exit mycdev_exit(void)
    {
        pr_info("mycdev_exit is involked");
        cdev_del(&mycdev);
        unregister_chrdev_region(dev_num, 1);
        pr_info("mycdev driver unloaded\n");

    }

    module_init(mycdev_init);
    module_exit(mycdev_exit);

    MODULE_LICENSE("GPL");





































































