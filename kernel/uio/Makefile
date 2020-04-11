#ARCH:=
#CROSS_COMPILE:=

ifneq  ($(KERNELRELEASE),)
# in kernel source tree

obj-m := uio.o
obj-m += sample_uio/
obj-m += uio_devices/

else
# out out kernel source tree

KDIR:=/lib/modules/$(shell uname -r)/build
PWD:=$(shell pwd)

all:
	$(MAKE) -C $(KDIR) M=$(PWD) modules

clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean

endif

