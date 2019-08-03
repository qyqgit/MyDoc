#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <t_file.h>
int main(int argc, char *argv[]){
	int a = atoi(argv[1]);
	
	while(a--){
		pid_t pid = fork();
		if(pid == -1)E_MSG("fork", -1);
		if(pid == 0){
			break;//4*1
		}	
		else{
			//break;//1*4
		}
		
		
	}
	sleep(30);
}
