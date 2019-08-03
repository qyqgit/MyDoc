#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include <dirent.h>
#include <string.h>
void readfile(char *path, char *name){
	struct stat buf;
	int status = stat(path, &buf);
	if(status == -1){
		perror(path);
	}

	
	printf("%lu\t", buf.st_ino);
	
	if(S_ISREG(buf.st_mode))printf("-");
	if(S_ISDIR(buf.st_mode))printf("d");
	(buf.st_mode & S_IRUSR) ? printf("r") : printf("-");
	(buf.st_mode & S_IWUSR) ? printf("w") : printf("-");
	(buf.st_mode & S_IXUSR) ? printf("x") : printf("-");
	(buf.st_mode & S_IRGRP) ? printf("r") : printf("-");
	(buf.st_mode & S_IWGRP) ? printf("w") : printf("-");
	(buf.st_mode & S_IXGRP) ? printf("x") : printf("-");
	(buf.st_mode & S_IROTH) ? printf("r") : printf("-");
	(buf.st_mode & S_IWOTH) ? printf("w") : printf("-");
	(buf.st_mode & S_IXOTH) ? printf("x\t") : printf("-\t");
	
	
	printf("%u\t", buf.st_nlink);
	
	printf("%s\t", (getpwuid(buf.st_uid))->pw_name);
	
	printf("%s\t", (getgrgid(buf.st_gid))->gr_name);
	
	printf("%lu\t", buf.st_size);
	
	char timbuf[255] = {0};
	strncpy(timbuf, ctime(&buf.st_mtime), 24);
	printf("%s\t", timbuf);
	printf("%s\n", name);
}
int isdir(char *path){
	struct stat buf;
	int status = stat(path, &buf);
	if(status == -1){
		perror("stat");
		return -1;
	}
	if(S_ISDIR(buf.st_mode))
		return 1;
	else
		return 0;
}
int main(int argc, char *argv[]){
	if(argc == 1){
		struct dirent *p_dirent;
		DIR *p_dir = opendir(".");
		if(p_dir == NULL){
			perror("opendir");
			return -1;
		}
		while(p_dirent = readdir(p_dir)){
			readfile(p_dirent->d_name, p_dirent->d_name);
		}	
		closedir(p_dir);
	}

	int index = 1;
	while(index < argc) {
		printf("%s:\n",argv[index]);
		if(isdir(argv[index])){
			char pathbuf[100] = {0};

			struct dirent *p_dirent;
			DIR *p_dir = opendir(argv[index]);
			if(p_dir == NULL){
				perror("opendir");
				return -1;
			}
			while(p_dirent = readdir(p_dir)){
				strcpy(pathbuf, argv[index]);
				strcat(pathbuf, "/");
				readfile(strcat(pathbuf,p_dirent->d_name), p_dirent->d_name);
				pathbuf[0] = '\0';
			}
			
			closedir(p_dir);
		}else
			readfile(argv[index], argv[index]);
		index++;
	}
	return 0;
}
