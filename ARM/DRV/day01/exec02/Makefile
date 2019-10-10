obj-m += test.o helloworld.o
all:
	make -C /home/vi/kernel SUBDIRS=$(PWD) modules
clean:
	make -C /home/vi/kernel SUBDIRS=$(PWD) clean
