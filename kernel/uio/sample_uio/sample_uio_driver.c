/*
 * File Name: sample_uio.c
 * Description: linux UIO driver example
 * Author: name <name@xxxx>
 * Created Time: 2020-04-10 17:40:22
 *
 */

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/platform_device.h>
#include <linux/uio_driver.h>
#include <linux/of.h>

MODULE_AUTHOR("Tux Sama");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("A Simple UIO driver");

struct sample_uio_context {
	uint32_t status;

	uint32_t reserved[8];
};

struct sample_uio_dev {
	struct uio_info *uioinfo;

	struct sample_uio_context *ctx;
};


static int sample_uio_probe(struct platform_device *pdev)
{
	struct sample_uio_dev *p_uio_dev;
	struct uio_info *uioinfo;

	pr_info("%s %d\n", __func__, __LINE__);

	p_uio_dev = devm_kzalloc(&pdev->dev,
			sizeof(struct sample_uio_dev), GFP_KERNEL);
	if (p_uio_dev == NULL)
		return -ENOMEM;

	p_uio_dev->uioinfo = devm_kzalloc(&pdev->dev,
			sizeof(struct uio_info), GFP_KERNEL);
	if (p_uio_dev->uioinfo == NULL)
		return -ENOMEM;

	p_uio_dev->ctx = devm_kzalloc(&pdev->dev,
			sizeof(struct sample_uio_context), GFP_KERNEL);
	if (p_uio_dev->ctx == NULL)
		return -ENOMEM;

	uioinfo = p_uio_dev->uioinfo;

	uioinfo->name = "uio_sampe";
	uioinfo->version = "V0.1";

	uioinfo->mem[0].name = "phys_mem";
	uioinfo->mem[0].memtype = UIO_MEM_PHYS;
	uioinfo->mem[0].addr = 0x0;
	uioinfo->mem[0].size = 0x1000;

	uioinfo->mem[1].name = "ctx";
	uioinfo->mem[1].memtype = UIO_MEM_LOGICAL;
	uioinfo->mem[1].addr = (phys_addr_t)p_uio_dev->ctx;
	uioinfo->mem[1].size = sizeof(struct sample_uio_context);

	if (uio_register_device(&pdev->dev, uioinfo))
		return -ENODEV;

	platform_set_drvdata(pdev, p_uio_dev);

	return 0;
}

static int sample_uio_remove(struct platform_device *pdev)
{
	struct sample_uio_dev *p_uio_dev;
	struct uio_info *uioinfo;

	pr_info("%s %d\n", __func__, __LINE__);

	p_uio_dev = platform_get_drvdata(pdev);
	if (p_uio_dev == NULL)
		return 0;

	uioinfo = p_uio_dev->uioinfo;

	uio_unregister_device(uioinfo);

	return 0;
}

static int sample_uio_runtime_nop(struct device *dev)
{
	/* Runtime PM callback shared between ->runtime_suspend()
	 * and ->runtime_resume(). Simply returns success.
	 *
	 * In this driver pm_runtime_get_sync() and pm_runtime_put_sync()
	 * are used at open() and release() time. This allows the
	 * Runtime PM code to turn off power to the device while the
	 * device is unused, ie before open() and after release().
	 *
	 * This Runtime PM callback does not need to save or restore
	 * any registers since user space is responsbile for hardware
	 * register reinitialization after open().
	 */
	return 0;
}

static const struct dev_pm_ops sample_uio_pm_ops = {
	.runtime_suspend = sample_uio_runtime_nop,
	.runtime_resume = sample_uio_runtime_nop,
};

static const struct of_device_id sample_uio_match[] = {
	{ /* empty for now */ },
};
MODULE_DEVICE_TABLE(of, sample_uio_match);

static struct platform_driver sample_uio_plat_driver = {
	.probe = sample_uio_probe,
	.remove = sample_uio_remove,
	.driver = {
		.name = "sample_uio",
		.pm = &sample_uio_pm_ops,
		.of_match_table = of_match_ptr(sample_uio_match),
	},
};

module_platform_driver(sample_uio_plat_driver);

