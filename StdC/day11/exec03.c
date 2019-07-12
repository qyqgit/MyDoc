#include <stdio.h>
int main(int argc, char** argv){
	int num = 0;
	for(num = 0; num <= argc - 1; num++){
		printf("%s\n", *(argv + num));
	}
	char ch	= 'r';
	int val	= 34;
	void *p_v = &ch;
	printf("%c\n", *(char *)p_v);
	p_v = &val;
	printf("%d\n", *(int *)p_v);

	int *p_val = &val;
	char *p_ch = &ch;
	p_v = &p_ch;
	printf("%c\n", **(char **)p_v);
	p_v = &p_val;
	printf("%d\n", **(int **)p_v);
	return 0;
}
