#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#ifndef N
	#define N 7
#endif 
#ifndef MAX
	#define MAX 36
#endif
int main(){
	int *p = NULL;

	p = (int*)malloc(N * sizeof(int));
	srand(time(0));
	for(int i = 0; i < N; i++){
		p[i] = rand() % MAX + 1;
	}
	
	for(int i = 0; i < N; printf("%d ", p[i++]));
	printf("\n");
	free(p);


}
