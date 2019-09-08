//#include <t_file.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#define E_MSG(STR,VAL) do{perror(STR);return(VAL);}while(0)
int main(void){
	int status = 0;
	pid_t pid = fork();
	if(pid == -1)E_MSG("fork", -1);
	if(pid == 0){
		printf("child\n");
		getchar();
		exit(321);//&0377
	}else{
		printf("14parent\n");
		//wait(&status);//阻塞等待子进程的终止
		waitpid(-1, &status, 0);//阻塞等待子进程的终止
		//waitpid(-1, &status, WNOHANG);
		printf("16parent\n");
		
		if(WIFEXITED(status))
			printf("exit code %d\n", WEXITSTATUS(status));
		if(WIFSIGNALED(status))
			printf("signum %d\n", WTERMSIG(status));
	}
}
