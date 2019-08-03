#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
void bye(void){
	printf("bye.\n");
	return;
}
int main(void){
	//向进程注册遗言函数
	atexit(bye);
	getchar();
	atexit(bye);
	getchar();
	pid_t pid = fork();
	if(pid == 0){
		printf("%d\n", getpid());
		atexit(bye);
		printf("%d\n", getpid());//子进程继承父进程注册的遗言函数
	}else{
		printf("%d\n", getpid());
		atexit(bye);
		printf("%d\n", getpid());
	}
	exit(-1);
}
