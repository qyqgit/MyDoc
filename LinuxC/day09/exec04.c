#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <string.h>
#include <stdio.h>
int main(int argc, char *argv[]){
	if(argc < 3)
		return -1;
	int status = kill(atoi(argv[1]), atoi(argv[2]));
	if(status == 0)
		printf("success\n");
}
