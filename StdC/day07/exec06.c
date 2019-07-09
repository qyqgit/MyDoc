#include<stdio.h>
int main(){
	char ch = 't';
	int val = 10;
	void *p_v = 3;
	p_v = &ch;
	printf("%c\n",*(char*) p_v);
	p_v = &val;
	printf("%d\n",*(int*) p_v);
	return 0;
}
