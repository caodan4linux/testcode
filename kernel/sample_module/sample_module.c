/*
 * File Name: sample_module.c
 * Description: linux kernel module sample
 * Author: name <name@xxxx>
 * Created Time: 2020-04-10 17:00:22
 *
 */

#include <linux/kernel.h>
#include <linux/module.h>

MODULE_AUTHOR("Tux Sama");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("A Simple kernel module");


static int __init sample_init(void)
{
	pr_info("%s %d\n", __func__, __LINE__);

	return 0;
}

static void __exit sample_exit(void)
{
	pr_info("%s %d\n", __func__, __LINE__);
}


module_init(sample_init);

module_exit(sample_exit);
