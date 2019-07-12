#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
	int *p = (int*)malloc(sizeof(int) * 5);
	srand(time(0));
	if(!p)
		return 0;
	for(int i = 0; i < 5; i++){
		*(p + i) = i;
	}

	for(int i = 0; i < 5; i++){
		printf("%d\n", *(p + i));
	}
	for(int i = 0; i < 5; i++){
		*(p + i) = rand() % 36 + 1;
	}
	for(int i = 0; i < 5; i++){
		printf("%d\n", *(p + i));
	}
	free(p);
	p = NULL;
	return 0;
}
