/*
 * File Name: sample_uio_device.c
 * Description:
 * Author: name <name@xxxx>
 * Created Time: 2020-04-10 19:24:02
 *
 */

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/platform_device.h>

MODULE_AUTHOR("Tux Sama");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("A Simple UIO device");


static struct resource sample_uio_resource[] = {
	[0] = {
		.start = 0x0,
		.end   = 0x0 + 0x1000 - 1,
		.flags = IORESOURCE_MEM,
	},
};

static struct platform_device sample_uio_plat_device = {
       .name             = "sample_uio",
       .id               = -1,
       .num_resources    = ARRAY_SIZE(sample_uio_resource),
       .resource         = sample_uio_resource,
};

static int __init sample_uio_device_init(void)
{
	int rc;

	pr_info("%s %d\n", __func__, __LINE__);

	rc = platform_device_register(&sample_uio_plat_device);

	return rc;
}

static void __exit sample_uio_device_exit(void)
{
	pr_info("%s %d\n", __func__, __LINE__);

	platform_device_unregister(&sample_uio_plat_device);
}


module_init(sample_uio_device_init);

module_exit(sample_uio_device_exit);
