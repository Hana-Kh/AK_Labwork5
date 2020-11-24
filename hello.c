#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/printk.h>
#include <linux/types.h>

MODULE_AUTHOR("Hana Khalil <hanka100h@gmail.com>");
MODULE_DESCRIPTION("Hello, world in Linux Kernel Training");
MODULE_LICENSE("Dual BSD/GPL");

static uint hw_count = 1;
module_param(hw_count,uint,S_IRUGO);
MODULE_PARM_DESC(hw_count, "This parameter is counter of hello world");

static int __init hello_init(void)
{
	uint i = 0;
  	printk(KERN_INFO "Input %d\n", hw_count);

	if(hw_count == 0) 
	{
		printk(KERN_WARNING "You cannot enter 0");
	}
	else if(hw_count >=5 && hw_count <= 10) 
	{
		printk(KERN_WARNING "Number should be less than 5");
	} 
	else if(hw_count > 10) 
	{
		printk(KERN_ERR "The parameter is greater than 10");
		return -EINVAL;
	}

	for(i = 0; i < hw_count; i++){
		printk(KERN_INFO "Hello, world!\n");
	}
	
	return 0;
}

static void __exit hello_exit(void)
{
	/* Do nothing here right now */
}

module_init(hello_init);
module_exit(hello_exit);
