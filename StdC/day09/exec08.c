#include <stdio.h>
#define MIN(a, b, c) (((a) > (b) ? (b) : (a) ) > (c) ? (c) : ((a) > (b) ? (b) : (a)))
int main(){
	int a = 0;
	int b = 0;
	int c = 0;
	scanf("%d%d%d", &a, &b, &c);
	printf("%d\n", MIN(a, b, c));
}
