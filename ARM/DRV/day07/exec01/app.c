#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main(int argc, char *argv[]){
	int fd;
	if(argc != 2){
		printf("Usage:%s <r|w>.\n", argv[0]);
		return -1;
	}
	fd = open("/dev/mybtn", O_RDWR);
	if(fd < 0){
		printf("open btn device fail.");
		return -1;
	}
	if(!strcmp(argv[1], "r"))
		read(fd, NULL, 0);//读,休眠等待唤醒
	else if(!strcmp(argv[1], "w"))
		write(fd, NULL, 0);//写,唤醒读进程
	close(fd);
	return 0;
}
