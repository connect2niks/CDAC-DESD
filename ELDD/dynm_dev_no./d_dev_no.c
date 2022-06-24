//#include <linux/kdev_t.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>

//creating the dev with statically allocation of major and minor number

dev_t dev = 0;

//Module init function

static int __init d_dev_no_init(void)
{
    // Allocating Mojor Number
    if((alloc_chrdev_region(&dev, 0, 1, "simplechardevice2")) <0)
    {
        printk(KERN_INFO"Cannot allocate major number for device 1\n");
        return -1;
    }

    printk(KERN_INFO"Major = %d, Minor = %d\n",MAJOR(dev), MINOR (dev));
    printk(KERN_INFO"Kernel Module Inserted Successfully....\n");
    return 0;
}

// Module exit function

static void __exit d_dev_no_exit(void)
{
    unregister_chrdev_region(dev, 1);
    printk(KERN_INFO"Kernel Module Removed Successfully....\n");
    
}

module_init(d_dev_no_init);
module_exit(d_dev_no_exit);

MODULE_LICENSE("GPL");