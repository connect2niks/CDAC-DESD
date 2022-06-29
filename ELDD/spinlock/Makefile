	obj-m:=spin_lock.o
	KERNDIR=/lib/modules/$(shell uname -r)/build
	PWD:=$(shell pwd)

default:
	$(MAKE) -C $(KERNDIR) M=$(PWD) modules
	gcc -o write_app1 write_app1.c
	gcc -o write_app2 write_app2.c
	gcc -o read_app read_app.c

clean:
	$(MAKE) -C $(KERNDIR) M=$(PWD) clean
	rm write_app1 write_app2 read_app

