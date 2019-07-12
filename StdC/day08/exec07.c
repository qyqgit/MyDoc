#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
	char str[100] = {0};
	int sum = 0;
	int a = 0;
	char *p = NULL;

	p = str;
	fgets(str, 60, stdin);

	do{
		a = atoi(p);
		sum += a;
		p += ((strstr(p, ",") - p));
		p++;
	}while(strstr(p, ","));
	printf("%d\n", sum + atoi(p));
}
