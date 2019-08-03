#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
int main(void){
	int pipefd[2];
	int status = pipe(pipefd);
	char buf[100];// = {0};
	printf("status:%d\n",status);
	pid_t pid = fork();
	if(pid == -1){
		perror("fork");
		return -1;
	}
	if(pid == 0){
		printf("child start\n");
		close(pipefd[1]);
		int len = read(pipefd[0], buf, 10);
		printf("child:%s %d\n", buf, len);
		close(pipefd[0]);
		printf("child end\n");
		//exit(0);
	}else{
		printf("parent start\n");
		close(pipefd[0]);
		write(pipefd[1], "2333", strlen("233333"));
		close(pipefd[1]);
		//wait(NULL);
		printf("parent end\n");

	}
	return 0;
}
