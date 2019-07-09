#include<stdio.h>
#include<string.h>
int main(){
	char str[100] = "abc";
	printf("%d\n", strlen(str));
	printf("%d\n", sizeof(str));

	char *p_str = NULL;
	p_str = strcat(str, "xyz");
	printf("%s\n",str);
	printf("%s\n",p_str);

	strncat(str, "aaabbbccc", 6);
	printf("%s\n", str);

	printf("%d\n", strcmp("abe", "abd"));

	printf("%d\n", strncmp("abc","abd", 2));

	printf("%s\n", strcpy(str, "iot"));

	printf("%s\n", strncpy(str, "123123", 2));
}
