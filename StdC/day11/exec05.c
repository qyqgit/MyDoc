#include <stdio.h>
typedef int (*pfunc_add_t)(int, int);
typedef int (*pfunc_sub_t)(int, int);
int add(int a, int b){
	return a + b;
}
int sub(int a, int b){
	return a - b;
}
int main(){
	int (*p_add)(int, int) = NULL;
	p_add = add;
	printf("add:%p\n", add);
	printf("%d\n", p_add(3, 4));

	int (*p_sub)(int, int);
	p_sub = sub;
	printf("sub:%p\n", sub);
	printf("%d\n", sub(4, 3));

	pfunc_add_t p_add1 = NULL;
	p_add1 = add;
	printf("%d\n", p_add1(4, 5));
	return 0;
}
