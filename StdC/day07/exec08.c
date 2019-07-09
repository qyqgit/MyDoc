#include<stdio.h>
#include<stdlib.h>
void swap(int *a, int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void swap1(void *a, void *b, int size){
	char tmp = 0;
	for(int i = 0; i < size; i++){
		tmp = *((char*)a + i);
		*((char*)a + i) = *((char*)b + i);
		*((char*)b + i) = tmp;
	}

}
int main(){
	int a = 3;
	int b = 7;
	double aa = 3.0;
	double bb = 7.0;
	
	swap(&a, &b);
	printf("a=%d b=%d\n", a, b);

	swap1(&aa, &bb, sizeof(double));
	printf("aa=%lf bb=%lf\n", aa, bb);
	return 0;
}
