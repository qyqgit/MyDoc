#include <t_file.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
int main(int argc, char *argv[]){
	struct stat buf;
	int status = stat(argv[1], &buf);
	if(status == -1)E_MSG("stat", -1);
	//struct passwd pswd;
	struct passwd *p_pswd = NULL;//&pswd;
	p_pswd = getpwuid(buf.st_uid);
	
	printf("%s ", argv[1]);
	
	printf("%lu ", buf.st_ino);
	
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
	(buf.st_mode & S_IXOTH) ? printf("x ") : printf("- ");
	
	
	printf("%u ", buf.st_nlink);
	
	printf("%s ", p_pswd->pw_name);
	
	printf("%s ", (getgrgid(buf.st_gid))->gr_name);
	
	printf("%lu ", buf.st_size);
	
	printf("%s ", ctime(&buf.st_mtime));

#if 0
	printf("uid:	%u\t", buf.st_uid);
	printf("gid:	%u\t", buf.st_gid);
	printf("mode:	%o\t", buf.st_mode);
	switch (buf.st_mode & S_IFMT) {
		case S_IFBLK:  printf("block device\t");            break;
		case S_IFCHR:  printf("character device\t");        break;
		case S_IFDIR:  printf("directory\t");               break;
		case S_IFIFO:  printf("FIFO/pipe\t");               break;
		case S_IFLNK:  printf("symlink\t");                 break;
		case S_IFREG:  printf("regular file\t");            break;
		case S_IFSOCK: printf("socket\t");                  break;
		default:       printf("unknown?\t");                break;
	}
	printf("usr passwd:	%s\t", p_pswd->pw_passwd);
	printf("modify time:	%ld\t", buf.st_mtim.tv_sec);
	printf("modify time:	%ld\t", buf.st_mtime);
#endif
	return 0;
}
