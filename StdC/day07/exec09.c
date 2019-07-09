#include<stdio.h>
int a = 0;
int* read(void){
	//static int a = 0;
	scanf("%d", &a);
	return &a;
}
int main(){
	printf("%d\n",*read());
	return 0;
}
