#include<stdio.h>
#define SHRIMP		1
#define CHICKEN		2
int main(){
	int a = 0;
	scanf("%d", &a);
	#ifdef ZHAO
		if(a == SHRIMP)
			printf("don't have.\n");
		if(a == CHICKEN)
			printf("really don't have.\n");
	#else
		if(a == SHRIMP)
			printf("have.\n");
		if(a == CHICKEN)
			printf("don't have.\n");
	#endif		
}
