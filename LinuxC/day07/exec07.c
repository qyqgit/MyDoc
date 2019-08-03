#include <t_file.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
int main(void){
	pid_t pid = fork();
	if(pid == -1)E_MSG("fork", -1);
	if(pid == 0){
		printf("9child pid:%d\n", getpid());
		printf("10child ppid:%d\n" ,getppid());
		sleep(3);
		
		printf("13child ppid:%d\n", getppid());//orphan process
		sleep(30);
		exit(0);
	}else{
		printf("17parent pid:%d\n", getpid());
		sleep(1);
	}
	return 0;
}
