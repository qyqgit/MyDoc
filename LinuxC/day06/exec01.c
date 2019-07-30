#include <t_file.h>
#include <sys/mman.h>
int main(void){
	int prot = PROT_READ | PROT_WRITE;
	int flags = MAP_PRIVATE | MAP_ANONYMOUS;
	//将物理地址映射到进程的虚拟地址空间
	void *mp = mmap(NULL, 1024, prot, flags, -1, 0);
	if(mp == MAP_FAILED)E_MSG("mmap", -1);
	strcpy(mp, "12345");
	printf("%s\n", (char*)mp);
	munmap(mp, 1024);
	return 0;
}
