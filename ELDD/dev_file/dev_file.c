// Creating device file autiomatically

//#include <linux/kdev_t.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
# include <linux/device.h>

//creating the dev with statically allocation of major and minor number

dev_t dev = 0;
static struct class *dev_class;
//Module init function

static int __init devicefile_init(void)
{
    // Allocating Major Number
    if((alloc_chrdev_region(&dev, 0, 1, "simplechardevice")) <0)
    {
        printk(KERN_INFO"Cannot allocate major number for device 1\n");
        return -1;
    }
    pr_info("Major = %d Minor = %d \n",MAJOR(dev), MINOR(dev));

    //Creating struct class
    if((dev_class = class_create(THIS_MODULE,"simplechardevice_class")) == NULL)
    {
        pr_err("Cannot create the struct class for device\n");
        goto r_class;
    }

    // Creating device

    if((device_create(dev_class,NULL,dev,NULL,"simplechardevice_device")) == NULL)
    {
        pr_err("Cannot create the device\n");
        goto r_device;
    }

    pr_info("Kernel Module Inserted Successfully...\n");
    return 0;

r_device:
        class_destroy(dev_class);
r_class:
        unregister_chrdev_region(dev, 1);
        return -1;
}

// Module exit function

static void __exit devicefile_exit(void)
{
    device_destroy(dev_class,dev);
    class_destroy(dev_class);
    unregister_chrdev_region(dev, 1);
    pr_info(KERN_INFO"Kernel Module Removed Successfully....\n");
    
}

module_init(devicefile_init);
module_exit(devicefile_exit);

MODULE_LICENSE("GPL");