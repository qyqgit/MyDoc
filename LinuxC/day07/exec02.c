#include <t_file.h>
#include <unistd.h>
int main(void){
	pid_t pid = fork();
	printf("pid:%d\n", pid);
	if(pid == -1)E_MSG("fork", -1);
	if(pid == 0){
		printf("child:%d %d\n", getpid(), pid);
	} else {
		printf("parent:%d %d\n", getpid(), pid);
	}
	printf("both\n");
	return 0;
}
