#include <linux/init.h>   /* for __init and __exit */
#include <linux/module.h> /* for module_init and module_exit */
#include <linux/printk.h> /* for printk call */
#include <linux/interrupt.h>  /* for disable_irq() */

MODULE_AUTHOR("SI");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Disable a specific interrupt");

// TODO: add the interrupt number
int irq = ...; /* E.g. timer interrupt */

static int __init my_init(void)
{
        printk(KERN_DEBUG "Disabling interrupt %u\n", irq);
	disable_irq(irq);

        return 0;
}

static void __exit my_exit(void)
{
        printk(KERN_DEBUG "Re-enabling interrupt\n");
	enable_irq(irq);
}

module_init(my_init);
module_exit(my_exit);
