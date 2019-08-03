#include <stdio.h>
#include <unistd.h>
int main(void){
	alarm(1);
	for(int i = 1; i > 0; i++){
		printf("i=%d\n", i);
	}
	return 0;
}
