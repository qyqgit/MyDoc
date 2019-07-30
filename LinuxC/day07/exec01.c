#include <t_file.h>
#include <sys/types.h>
#include <dirent.h>
int main(int argc, char *argv[]){
	DIR *dir = opendir(argv[1]);
	struct dirent *dirp;
	if(dir == NULL)E_MSG("opendir", -1);
	while(dirp = readdir(dir))
		printf("%lu\t%s\n", dirp->d_ino, dirp->d_name);
	closedir(dir);
	return 0;
}
