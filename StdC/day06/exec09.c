#include<stdio.h>
int main(){
	int x = 0;
	int y = 0;
	char ch = 0;
	printf("请输入要打印的行列：");
	scanf("%d %d",&x, &y);
	printf("请输入要打印的字符：");
	scanf("%*[^\n]");
	scanf("%c",&ch);
	return 0;	
}
