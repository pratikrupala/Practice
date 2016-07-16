# Comment/uncomment below line to disable/enable debugging
DEBUG=y

ifdef ($(DEBUG),y)
	DEBFLAGS := -O -g -DSCULL_DEBUG
else
	DEBFLAGS := -O
endif

EXTRA_CFLAGS += $(DEBFLAGS)
EXTRA_CFLAGS += -I$(INCDIR)

ifneq ($(KERNELRELEASE),)
	obj-m := scull.o
else
	KERNELDIR ?= /lib/modules/$(shell uname -r)/build
	PWD	  := $(shell pwd)

default:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) INCDIR=$(PWD) modules

clean:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) clean

endif
