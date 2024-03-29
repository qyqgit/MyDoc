#include <t_file.h>
#include <stdio.h>
#include <signal.h>
void handle(int n){
	printf("sig:%d\n", n);
}
int main(int argc, char *argv[]){
	signal(2, handle);
	signal(3, handle);
	signal(45, handle);

	sigset_t sigset, oldset, pset;
	sigemptyset(&sigset);
	perror("sigemptyset");

	sigaddset(&sigset, 2);
	perror("sigaddset");

	sigaddset(&sigset, 3);
	perror("sigaddset");

	sigaddset(&sigset, 45);
	perror("sigaddset");

	sigaddset(&sigset, 9);
	perror("sigaddset");

	int sm = sigprocmask(SIG_BLOCK, &sigset, &oldset);
	if(sm == -1)E_MSG("sigprocmask", -1);
	int num = 5;
	while(1){
		sigpending(&pset);
		printf("sig2 pending:%d\n", sigismember(&pset, 2));
		sleep(1);
		if(!num--){
			sm = sigprocmask(SIG_SETMASK, &oldset, NULL);
			if(sm == -1)E_MSG("sigprocmask", -1);
		}
	}
	return 0;
}
