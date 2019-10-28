/*
 * server.c
 *
 *  Created on: 2019年8月5日
 *      Author: vim
 */
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "t_net.h"
#include "trans.h"
#include <signal.h>
void handle(int n){
	printf("kill z+\n");
	wait(NULL);
	return;
}
int main(int argc, char *argv[]){
	signal(SIGCHLD, handle);
	int socketfd = mylisten(4433, 5);
	while(1){
		int connectfd = h_accept(socketfd);
		if(connectfd == -1)return -1;
		//连接好后再创建子进程
		pid_t pid = fork();
		if(pid == -1){
			perror("fork");
			return -1;
		}
		if(pid == 0){
			close(socketfd);
			t_main(connectfd);
			close(connectfd);//关闭本次连接
			exit(0);
		}else{
			close(connectfd);
			//waitpid(-1, NULL, WNOHANG);//非阻塞等待子进程终止,但是会有僵尸进程产生
		}
	}
	return 0;
}

