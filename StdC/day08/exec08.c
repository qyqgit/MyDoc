#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
	char str[60] = {0};
	char *p_ch = str;
	int sum = 0;
	fgets(str, 60, stdin);
	if(strlen(str) == 59 && str[58] != '\n'){
		scanf("%*[^\n]");
		scanf("%*c");
	}
	while(1){
		sum += atoi(p_ch);
		p_ch = strstr(p_ch, ",");
		if(!p_ch){
			break;
		}
		p_ch++;

	}
	printf("%d\n",sum);
	return 0;
}
