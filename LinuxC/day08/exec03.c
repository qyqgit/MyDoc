#include <t_file.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
int main(int argc, char* argv[]){
	char *p_argv[] = {"ps","-o", "pid,ppid,pgrp,comm", NULL};
	pid_t pid = fork();
	if(pid == -1)E_MSG("fork", -1);
	if(pid == 0){
		printf("child\n");
		//execvp("ps", p_argv);
		execlp("ps", p_argv[0], p_argv[1], p_argv[2], NULL);
		//以下两条语句什么时候会执行？
		perror("execvp");
		exit(0);
	}else{
		wait(NULL);
		printf("parent\n");
	}
	return 0;
}
