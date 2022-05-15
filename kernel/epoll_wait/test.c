#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/miscdevice.h>
#include <linux/fs.h>

static int _test_module_open(struct inode *inode, struct file *p)
{
	return 0;
}

static const struct file_operations test_dev_fops = {
	.open = _test_module_open,
};

static struct miscdevice test_dev = {
	.minor = MISC_DYNAMIC_MINOR,
	.name  = "test_epoll",
	.fops  = &test_dev_fops,
};

static int __init test_module_init(void)
{
	int ret;

	pr_info("test_module init\n");

	ret = misc_register(&test_dev);
	if (ret) {
		pr_err("Fail to register misc device\n");
		return ret;
	}

	return 0;
}

static void __exit test_module_deinit(void)
{
	pr_info("test_module deinit\n");

	misc_deregister(&test_dev);
}

module_init(test_module_init);
module_exit(test_module_deinit);

MODULE_AUTHOR("Tux Sama");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("epoll wait test");
