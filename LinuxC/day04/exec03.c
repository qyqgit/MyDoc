#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
int main(void){
	pid_t pid = getpid();
	printf("pid:%d\n", pid);
	char *p = (char*)malloc(1024);
	printf("&p:%p\n", &p);
	printf("p:%p\n", p);
	char *q = "111222333";
	strcpy(p, q);
	free(p);
	p = (char*)malloc(3024);
	printf("%s\n", p);
	getchar();

}
