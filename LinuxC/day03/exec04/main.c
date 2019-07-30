#include <stdio.h>
#include <dlfcn.h>
#include "t_math.h"
int main(int argc, char* argv[]){
	static int aa = 0;
	int bb = 2;
	void* p_h = dlopen(argv[1], RTLD_NOW);
	if(p_h == NULL){
		printf("fopen fail.");
		return -1;
	}
	printf("p_h:%p\n",p_h);
	int (*t_add)(int, int);
	int (*t_sub)(int, int);
	int (*t_mul)(int, int);
	int (*t_div)(int, int);
	t_add = dlsym(p_h, "t_add");
	t_sub = dlsym(p_h, "t_sub");
	t_mul = dlsym(p_h, "t_mul");
	t_div = dlsym(p_h, "t_div");
	printf("%d + %d = %d\n", aa, bb, t_add(aa, bb));
	printf("%d - %d = %d\n", aa, bb, t_sub(aa, bb));
	printf("%d * %d = %d\n", aa, bb, t_mul(aa, bb));
	printf("%d / %d = %d\n", aa, bb, t_div(aa, bb));
	dlclose(p_h);
	return 0;
}
