#include <linux/init.h>   /* for __init and __exit */
#include <linux/module.h> /* for module_init and module_exit */
#include <linux/printk.h> /* for printk call */

MODULE_AUTHOR("SI");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Hello world module");

static int __init my_init(void)
{
        printk(KERN_DEBUG "Hello, world!\n");

        return 0;
}

static void __exit my_exit(void)
{
        printk(KERN_DEBUG "Goodbye, world!\n");
}

module_init(my_init);
module_exit(my_exit);

