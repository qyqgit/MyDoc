#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
int main(int argc, char *argv[]){
	int fd = open(argv[1], O_WRONLY);
	if(fd == -1){
		perror("open");
		return -1;
	}
	int cnt = write(fd, "123456", strlen("123456789"));
	close(fd);
	printf("write:%d\n", cnt);
	return 0;
}
