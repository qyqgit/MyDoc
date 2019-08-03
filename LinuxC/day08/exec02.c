#include <t_file.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
int main(void){
	int status = 0;
	pid_t pid = fork();
	if(pid == -1)E_MSG("fork", -1);
	if(pid == 0){
		printf("child\n");
		sleep(10);
		printf("end sleep\n");
		exit(-1);//&0377
	}else{
		printf("14parent\n");
		//wait(&status);//阻塞等待子进程的终止
		sleep(20);
		int w = waitpid(-1, &status, WNOHANG);//非阻塞等待
		printf("16parent:w:%d\n", w);
		if(w){
			if(WIFEXITED(status))
				printf("exit code %d\n", WEXITSTATUS(status));
			if(WIFSIGNALED(status))
				printf("signum %d\n", WTERMSIG(status));
		}
	}
}
