#include<stdio.h>

#define TO_STR(a) 	#a
#define TEST_APPEND(a) 	test##a

int main(){
	char* a = TO_STR(123);
	int TEST_APPEND(1) = 0;
	int TEST_APPEND(2) = 0;
	test1 = 3;
	test2 = 4;
	printf("%s\n", a);
	printf("%d\n", test1);
	printf("%d\n", test2);
}
