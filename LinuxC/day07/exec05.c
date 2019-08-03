#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
void bye(int n, void *arg){
	printf("n = %d\targ = %s\n", n, (char*)arg);
	return;
}
int main(void){
	on_exit(bye, "li");
	getchar();
	fork();
	exit(321);
	//echo $?
}
