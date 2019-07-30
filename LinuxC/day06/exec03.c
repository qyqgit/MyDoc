#include <stdio.h>
#include <stdlib.h>
typedef union{
	short s;
	char c;
}u_t;
int main(void){
	int *p = (int*)malloc(sizeof(int));
	*p = 0x11223344;
	printf("%x\n", *p);
	printf("%x",*(char*)p);
	printf("%x",*((char*)p + 1));
	printf("%x",*((char*)p + 2));
	printf("%x\n",*((char*)p + 3));
	(*(char*)p == 0x44) ? printf("small\n") : printf("big\n");
	
	u_t u;
	u.s = 0x0001;
	(u.c) ? printf("small\n") : printf("big\n");
	return 0;
}
