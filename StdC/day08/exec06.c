#include<stdio.h>
int main(){
	int sum = 0;
	int a, b, c, d, e;
	char str[100] = {0};
	
	a = b = c = d = e = 0;	
	fgets(str, 100, stdin);
	sscanf(str, "%d, %d, %d, %d, %d", &a, &b, &c, &d, &e);
	sum = a + b + c + d + e;
	printf("%d\n", sum);
}
