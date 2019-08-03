#include <stdio.h>
extern char **environ;
int main(int argc, char *argv[], char *envp[]){
	int i = 0;
	while(environ[i]){
		printf("%s\n",environ[i]);
		i++;
	}
	printf("--------------------------------\n");
	int j = 0;
	while(envp[j]){
		printf("%s\n", envp[j]);
		j++;
	}
}
