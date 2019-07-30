#include <t_file.h>
#include <sys/mman.h>
int main(int argc, char *argv[]){
	int fd = open(argv[1], O_RDWR);
	if(fd == -1)E_MSG("open", -1);
	int prot = PROT_READ | PROT_WRITE;
	int flags = MAP_SHARED;
	void *p = mmap(NULL, 6, prot, flags, fd, 0);
	if(p == MAP_FAILED)E_MSG("mmap", -1);
	close(fd);//关闭文件描述符，不解除映像
	*((int*)p) = 0x30313233;
	munmap(p, 6);
	return 0;
}
