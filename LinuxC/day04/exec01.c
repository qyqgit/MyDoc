#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main(void){
	pid_t pid = getpid();
	printf("pid:%d\n", pid);
	char *str1 = "abc";
	char *str2 = "abc";
	printf("&str1:%p\n", &str1);
	printf("&str2:%p\n", &str2);
	printf("str1:%p\n", str1);
	printf("str2:%p\n", str2);
	getchar();
	char str3[50] = "efgh";
	printf("&str3:%p\n", &str3);
	printf("str3:%p\n", str3);
	return 0;
}
