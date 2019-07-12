#include<stdio.h>
int main(){
	int a, b, c, d, e;
	a = b = c = d = e = 0;
	char str[100] = {0};
	fgets(str, 99, stdin);
	sscanf(str, "%d%d%d%d%d", &a, &b, &c, &d, &e);
	sprintf(str, "%d,%d,%d,%d,%d\n", a, b, c, d, e);
	printf("%s",str);
}
