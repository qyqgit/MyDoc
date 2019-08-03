#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <stdio.h>
void handle(int n){
	printf("alarm\n");
}

unsigned int t_sleep(unsigned int seconds){
	signal(SIGALRM, handle);
	alarm(seconds);
	pause();
	return alarm(0);
}

int main(int argc, char *argv[]){
	
	while(1){
		t_sleep(1);
		printf("hello\n");
	}
	return 0;
	
}
