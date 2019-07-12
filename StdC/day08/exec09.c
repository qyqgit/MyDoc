#include<stdio.h>
int main(){
	char* str[] = {"abc", "def", "xyz", "111", "222"};
	for(int num = 0; num < 5; num++){
		printf("%s\n",str[num]);
	}
	return 0;

}
