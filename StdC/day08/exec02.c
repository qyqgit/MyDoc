#include<stdio.h>
int main(){
	char str[10] = {0};
	sprintf(str, "%d %g %c\n", 56, 3.2f, 'u');
	printf("%s",str);
	
	char ch = 'a';
	int a = 0;
	float b = 0.0f;
	sscanf("p 12 6.8","%c%d%g", &ch, &a, &b);
	printf("%g %c %d\n", b, ch, a);
	return 0;
}
