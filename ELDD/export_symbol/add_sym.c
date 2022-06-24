/* Kernel symbol Program */

//Header files begins //////////////////////////////////////////////////////////////////
#include <linux/module.h>  // This header contain the necessary stuff for the module
#include <linux/init.h>  // Required header for initialization and clean up funtionalities
#include <linux/kernel.h> 
//Header files ends //////////////////////////////////////////////////////////////////

MODULE_LICENSE("GPL");    //tells that module bears free module
MODULE_AUTHOR("NIKHIL_YADAV");  // Author name
MODULE_DESCRIPTION("Kernel Symbol"); // Description about the module
MODULE_ALIAS("NIKS");  // Another name of the module

static int my_add(int a, int b);

static int __init hello_init(void)
{
    printk(KERN_ALERT"\nHello World\n");  // KERN_ALERT is the priority message : Decides the seriousness of message
    return 0; // return 0 for sucessfull compilation
}

static int my_add(int a, int b)
{
    return (a+b);
}
//command to export symbol into symbol table
EXPORT_SYMBOL_GPL(my_add);


// To removes module from the kernel

static void __exit hello_exit(void)
{
    printk("\nGoodbye world \n");
}


module_init(hello_init);  //Module Initialization
module_exit(hello_exit);  // Module De-Initialization

//use add function in another module
