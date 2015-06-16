# Uncomment the following to enable debug.
DEBUG = y

ifeq ($(DEBUG),y)
	DBGFLAGS = -O -g -DML_DEBUG
else
	DBGFLAGS = -O2
endif

ccflags-y += $(DBGFLAGS)


ifneq ($(KERNELRELEASE),)
	obj-m := calc_module1.o calc_module2.o calc_module3.o

else
	KERNELDIR ?= /lib/modules/$(shell uname -r)/build
	PWD := $(shell pwd)

default:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules

clean:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) clean

endif
