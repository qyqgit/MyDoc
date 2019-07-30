//redirect.c
#include <stdio.h>
#include "t_file.h"
int main(int argc, char *argv[]){
	char *msg = "to screen.\n";
	char *msg1 = "to file.\n";
	int flags = O_WRONLY | O_CREAT | O_TRUNC;
	mode_t mode = 0644;
	int fd = open(argv[1], flags, mode);
	if(fd == -1)E_MSG("open", -1);
	//保存标准输出的文件描述符	
	int s_fd = dup(1);
	//将fd描述符拷贝到标准输出
	dup2(fd, 1);
	printf("printf\n");
	close(fd);
	printf("printf2\n");
	fputs("fputs_stdout\n", stdout);
	write(1, msg1, strlen(msg1));
	//恢复原来的状态
	dup2(s_fd, 1);
	close(s_fd);
	write(1, msg, strlen(msg));
	return 0;
}

