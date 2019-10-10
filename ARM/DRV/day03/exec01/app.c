#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    int fd;
    char ucmd;
    //cat /proc/devices
    //mknod /dev/myled c major 0
    fd = open("/dev/myled", O_RDWR);
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
	read(fd, &ucmd, sizeof(ucmd));
        printf("status:%d\n", ucmd);
    }

    if(!strcmp("w",argv[1])){
	if(argc != 3){
		printf("Usage: %s <w> <ucmd>\n", argv[0]);
		close(fd);
		return -1;
	}
        ucmd = atoi(argv[2]);
        write(fd, &ucmd, sizeof(ucmd));
    }

    close(fd);
    return 0;
}

