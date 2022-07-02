#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>

//creating the dev with statically allocation of major and minor number

dev_t dev = MKDEV(200,0);

//Module init function

static int __init mjmn_init(void)
{
    register_chrdev_region(dev, 1, "SimlpeCharDriver");  // /proc/SimpleCharDriver
    printk(KERN_INFO"Major = %d, Minor = %d\n",MAJOR(dev), MINOR (dev));
    printk(KERN_INFO"Kernel Module Inserted Successfully....\n");
    return 0;
}

// Module exit function

static void __exit mjmn_exit(void)
{
    unregister_chrdev_region(dev, 1);
    printk(KERN_INFO"Kernel Module Removed Successfully....\n");
    
}

module_init(mjmn_init);
module_exit(mjmn_exit);

MODULE_LICENSE("GPL");