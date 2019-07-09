//指针练习
#include<stdio.h>
int* get_max(int *a, int *b, int *c){
	if(*a > *b){
		*b = *a;
		if(*b > *c)
			*c = *b;
	} else if(*a <= *b) {
		if(*b > *c)
			*c = *b;
	}
	return c;
	
}
int main(){
	int val0 = 0;
	int val1 = 0;
	int val2 = 0;
	scanf("%d%d%d", &val0, &val1, &val2);
	printf("%d\n", *get_max(&val0, &val1, &val2));
	return 0;
	
}

