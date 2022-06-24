/* Kernel symbol Program module 2 */

//Header files begins //////////////////////////////////////////////////////////////////
#include <linux/init.h>  // Required header for initialization and clean up funtionalities
#include <linux/module.h>  // This header contain the necessary stuff for the module
#include <linux/kernel.h> 
#include "header.h"
//Header files ends //////////////////////////////////////////////////////////////////

MODULE_LICENSE("GPL");    //tells that module bears free module
MODULE_AUTHOR("NIKHIL_YADAV");  // Author name
MODULE_DESCRIPTION("Kernel Symbol"); // Description about the module
MODULE_ALIAS("NIKS");  // Another name of the module

static int one=1;
static int two=2;

static int __init add_init(void)
{
    printk(KERN_ALERT"\nWe are going to add\n");  // KERN_ALERT is the priority message : Decides the seriousness of message
    printk(KERN_ALERT"\nAddition :%d\n",my_add(one,two));  // KERN_ALERT is the priority message : Decides the seriousness of message
    
    
    return 0; // return 0 for sucessfull compilation
}

// To removes module from the kernel

static void __exit add_exit(void)
{
    printk("\nGoodbye \n");
}


module_init(add_init);  //Module Initialization
module_exit(add_exit);  // Module De-Initialization

//use add function in another module
