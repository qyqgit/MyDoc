#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
	int a = atoi("34abc");
	double b = atof("33.333abc");
	printf("%d\n", a);
	printf("%lg\n", b);

	char str[100] = {0};
	//scanf("%s",str);
	//printf("%s\n",str);

	fgets(str, 10, stdin);
	printf("%s\n", str);
	if(strlen(str) == 9 && str[8] != '\n'){
		scanf("%*[^\n]");
		scanf("%*c");
	}
	fgets(str, 10, stdin);
	printf("%s\n", str);
	return 0;
}
