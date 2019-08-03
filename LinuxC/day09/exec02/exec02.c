#include <t_file.h>
#include <sys/types.h>
#include <sys/stat.h>
int main(int argc, char *argv[]){
	int ff= mkfifo(argv[1], 0664);
	if(ff == -1)E_MSG("mkfifo", -1);
	return 0;
}
