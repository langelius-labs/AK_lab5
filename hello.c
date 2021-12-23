#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/proc_fs.h>
#include <linux/uaccess.h>

MODULE_AUTHOR("Hutsaliuk Oleh  IV-93");
MODULE_DESCRIPTION("Lab5");
MODULE_LICENSE("Dual BSD/GPL");

static int amount = 1;
module_param(amount, uint, S_IRUGO);
MODULE_PARM_DESC(times, "Amount of outputting Hello worlds");

static int __init hello_init(void)
{
  uint i = 0;

  if (amount == 0) {
    printk(KERN_WARNING "0 was entered, doing nothing....");
  } else if (amount >= 3 && amount <= 7) {
  		for (i = 0; i < amount; i++) {
    		printk(KERN_EMERG "Hello, world!\n");
  }
  } else if (amount > 10) {
    printk(KERN_ERR "Too many Hellos!!! Les than 7 pls)");
    return -EINVAL;
  }


  return 0;
}

static void __exit hello_exit(void)
{
  /* Do nothing here right now */
}

module_init(hello_init);
module_exit(hello_exit);
