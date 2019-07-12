#include<stdio.h>
int main(){
	char arr[100] = {0};
	char *p = NULL;
	
	scanf("%s", arr);
	p = arr;
	while(*p){
		if(*p == 'c')
			printf("%d\n", p - arr);
		p++;

	}

}
