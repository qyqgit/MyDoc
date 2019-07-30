#include <stdio.h>
#include <dlfcn.h>
typedef	int (*m_t)(int, int);
int main(int argc, char* argv[]){
	//打开动态库
	void *h = dlopen(argv[1], RTLD_NOW);
	if(h == NULL){
		printf("dlopen fail.%s\n", dlerror());
		return -1;
	}
	printf("dlopen success:%p\n", h);
	printf("main:%p\n", main);
	//在动态库中查找函数t_sub的入口地址
	void *f = dlsym(h, "t_sub");
	if(f == NULL){
		printf("%s\n", dlerror());
		return -1;
	}
	printf("t_sub:%p\n", f);
	m_t m = (m_t)f;
	printf("8 - 6 = %d\n", m(8, 6));
	dlclose(h);
	return 0;
}
