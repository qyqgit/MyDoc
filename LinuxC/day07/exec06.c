#include <t_file.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
int main(void){
	pid_t pid = fork();
	if(pid == -1)E_MSG("fork", -1);
	if(pid == 0){
		printf("child pid:%d\n" ,getpid());
		exit(0);
	}else{
		sleep(30);
	}
	return 0;
}
