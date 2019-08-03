#include <stdio.h>
#include <signal.h>
void handle(int n){
	printf("signal:%d\n", n);
	return;
}
int main(void){
	signal(2, SIG_IGN);
	signal(3, handle);
	//signal(3, SIG_DFL);
	signal(9, SIG_IGN);
	while(1);
	return 0;
}
