#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main(int argc, char *argv[]){
	char buf[100];
	int fd = open(argv[1], O_RDONLY);
	if(fd == -1){
		perror("open");
		return -1;
	}
	int cnt = read(fd, buf, 10);
	close(fd);
	printf("read:%s %d\n", buf, cnt);
	return 0;
}
