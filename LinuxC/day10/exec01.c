#include <stdio.h>
#include <signal.h>
int main(int argc, char *argv[]){
	sigset_t sigset;
	sigemptyset(&sigset);
	perror("sigemptyset");

	sigaddset(&sigset, 2);
	perror("sigaddset");

	sigaddset(&sigset, 3);
	perror("sigaddset");

	printf("sig3:%d\n", sigismember(&sigset, 3));
	
	sigdelset(&sigset, 3);
	perror("sigdelset");

	printf("sig3:%d\n", sigismember(&sigset, 3));
	while(1);
	return 0;
}
