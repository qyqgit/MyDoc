#include<stdio.h>
#include<string.h>
int main(){
	char str[100] = {0};
	char ret[100] = {0};
	char tmp[10] = {0};
	int a = 0;
	scanf("%d", &a);
	while(a >= 0){
		sprintf(tmp, "%d,", a);
		strcat(str, tmp);
		scanf("%d", &a);
	}
	//str[strlen(str) - 1] = 0;
	printf("%s\n", strncpy(ret, str, strlen(str) - 1));
}
