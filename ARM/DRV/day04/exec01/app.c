#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define LED_RD	0x10000001
#define LED_WT	0x10000002

int main(int argc, char *argv[])
{
    int fd;
    char ucmd;
    if(argc == 1){
        printf("Usage: %s <r>\n", argv[0]);
        printf("Usage: %s <w> <ucmd>\n", argv[0]);
        return -1;
    }
    fd = open("/dev/myledx", O_RDWR);
    if(fd < 0) {
        printf("open led device failed.\n");
        return -1;
    }
    if(!strcmp("r",argv[1])){
	if(argc != 2){
	    printf("Usage: %s <r>\n", argv[0]);
	    close(fd);
            return -1;
	}
	ioctl(fd, LED_RD, &ucmd);
        printf("status:%d\n", ucmd);
    }

    if(!strcmp("w",argv[1])){
	if(argc != 3){
		printf("Usage: %s <w> <ucmd>\n", argv[0]);
		close(fd);
		return -1;
	}
        ucmd = atoi(argv[2]);
	ioctl(fd, LED_WT, &ucmd);
    }

    close(fd);
    return 0;
}
