#include <stdio.h>
#include <string.h>
void *strcpy1(char *dest, const char *src){
	char *tmp = dest;
	while(*src){
		*dest++ = *src++;
	}
	*dest++ = *src++;
	return tmp;
}
int main(void){
	char *str1 = "12345";
	int size = 0;
	char str2[10];
	size = strlen(strcpy1(str2, str1));
	printf("%s\n", str2);
	printf("%d\n", size);
	return 0;
}
