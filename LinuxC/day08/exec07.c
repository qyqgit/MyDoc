#include <stdio.h>
#include <stdlib.h>
extern char **environ;
int main(void){
	char *p = getenv("dongdong");
	if(p != NULL){
		printf("%s\n", p);
		setenv("dongdong", "haha", 1);
		printf("%s\n", getenv("dongdong"));
		unsetenv("dongdong");
		p = getenv("dongdong");
		if(p == NULL)
			printf("unset succees.\n");
		clearenv();
		if(environ == NULL)
			printf("clearenv success.\n");
	}
	return 0;
}
