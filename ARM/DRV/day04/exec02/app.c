#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define LED_ON	0x10000001
#define LED_OFF	0x10000002

int main(int argc, char *argv[])
{
	int fd0,fd1,fd2,fd3;
	
	fd0 = open("/dev/myled0", O_RDWR);
	if(fd0 < 0) {
		printf("open led1 fail.\n");
		return -1;
	}

	fd1 = open("/dev/myled1", O_RDWR);
	if(fd1 < 0) {
		printf("open led2 fail.\n");
		return -1;
	}

	fd2 = open("/dev/myled2", O_RDWR);
	if(fd2 < 0) {
		printf("open led3 fail.\n");
		return -1;
	}

	fd3 = open("/dev/myled3", O_RDWR);
	if(fd3 < 0) {
		printf("open led4 fail.\n");
		return -1;
	}

	while(1) {
		ioctl(fd0, LED_ON);
		sleep(1);
		ioctl(fd1, LED_ON);
		sleep(1);
		ioctl(fd2, LED_ON);
		sleep(1);
		ioctl(fd3, LED_ON);
		sleep(1);
		ioctl(fd3, LED_OFF);
		sleep(1);
		ioctl(fd2, LED_OFF);
		sleep(1);
		ioctl(fd1, LED_OFF);
		sleep(1);
		ioctl(fd0, LED_OFF);
		sleep(1);
	}
	
	close(fd0);
	close(fd1);
	close(fd2);
	close(fd3);
	return 0;
}
