obj-m:= calling.o add_sym.o

KERNELDIR=/lib/modules/$(shell uname -r)/build

PWD:=$(shell pwd)

default:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules

clean:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) clean
	rm -rf /lib/modules/$(shell uname -r)/extra/*

install:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules_install
	depmod -a	