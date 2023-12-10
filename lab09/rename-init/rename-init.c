#include <linux/init.h>   /* for __init and __exit */
#include <linux/module.h> /* for module_init and module_exit */
#include <linux/printk.h> /* for printk call */
#include <linux/sched.h>  /* for current task_struct */

MODULE_AUTHOR("SI");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Rename the init process.");

static int __init my_init(void)
{
	/* Get the current PID. This will be the "insmod/modprobe" process */
	struct task_struct *p = current;

	/* Go to the parrent process until we reach "init" */
	while (p->pid != 1)
		p = p->parent;

        printk(KERN_DEBUG "Current init name %s\n", p->comm);

	strlcpy(p->comm, "SI-lab9", sizeof(p->comm));

        printk(KERN_DEBUG "New init name %s\n", p->comm);

        return 0;
}

static void __exit my_exit(void)
{
}

module_init(my_init);
module_exit(my_exit);

