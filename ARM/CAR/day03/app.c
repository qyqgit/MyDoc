#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <fcntl.h>

#define	GO	0x10000001
#define	BACK	0x10000002
#define STOP	0x10000003
#define LEFT	0x10000004
#define RIGHT	0x10000005

int main(int argc, char * argv[]){
	int fd = 0;
	fd = open("/dev/moto_misc_dev_file", O_RDWR);
	if(fd < 0){
		printf("open_fail\n");
		return 0;
	}
	printf("%d\n", fd);
	ioctl(fd, GO);
	sleep(3);
	ioctl(fd, BACK);
	sleep(3);
	ioctl(fd, STOP);
	sleep(3);
	ioctl(fd, LEFT);
	sleep(3);
	ioctl(fd, RIGHT);
	sleep(3);
	ioctl(fd, STOP);
	return 0;
}
