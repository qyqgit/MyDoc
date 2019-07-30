#include <stdio.h>
#include "t_math.h"
int testA;
int main(void){
	static int a = 0;
	int b = 2;
	printf("%d + %d = %d\n", a, b, t_add(a, b));
	printf("%d - %d = %d\n", a, b, t_sub(a, b));
	printf("%d * %d = %d\n", a, b, t_mul(a, b));
	printf("%d / %d = %d\n", a, b, t_div(a, b));
	return 0;
}
