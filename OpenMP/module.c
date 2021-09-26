#include<linux/module.h>	//for all kernel modules
#include<linux/kernel.h>	//for KERN_INFO
#include<linux/init.h>		//for __init& __exit macros

MODULE_LICENSE("GPL");
MODULE_AUTHOR("SRIRAM N");
MODULE_DESCRIPTION("A hello world module");#include<linux/module.h>	//for all kernel modules
#include<linux/kernel.h>	//for KERN_INFO
#include<linux/init.h>		//for __init& __exit macros

MODULE_LICENSE("GPL");
MODULE_AUTHOR("SRIRAM N");
MODULE_DESCRIPTION("A hello world module");

static int __init hello_init(void)
{
printk(KERN_INFO "Hello World!\n");
return 0;
}

static void __exit hello_cleanup(void)
{
printk(KERN_INFO "Cleaning up module.\n");
}

module_init(hello_init);
module_exit(hello_cleanup);

static int __init hello_init(void)
{
printk(KERN_INFO "Hello World!\n");
return 0;
}

static void __exit hello_cleanup(void)
{
printk(KERN_INFO "Cleaning up module.\n");
}

module_init(hello_init);
module_exit(hello_cleanup);
