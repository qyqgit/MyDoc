#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
int read_only(char *path){
	int num = 0;
	char buf[15] = {0};
	int handle = open(path, O_RDONLY);
	if(errno == 0){
		do{
			num = read(handle, buf, 10);
			buf[num] = '\0';
			printf("%s", buf);
		}while(num);
	} else 
		printf("read_only:%s\n",strerror(errno));
	close(handle);
	return num;
}
void write_safe(char *path){
	//mode_t mode = 0664;
	int handle = open(path, O_WRONLY | O_CREAT | O_EXCL, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
	perror("write_safe");
	close(handle);
}
void write_new(char *path){
	int handle = open(path, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
	perror("write_new");
	close(handle);
}
void write_unmask(char *path){
	int handle = open(path, O_WRONLY | O_CREAT | O_TRUNC, umask(0777));
	perror("write_new");
	close(handle);
}
int main(int argc, char *argv[]){
	read_only(argv[1]);
	//write_safe(argv[1]);
	//write_new(argv[1]);
	//write_unmask(argv[1]);


	
}
