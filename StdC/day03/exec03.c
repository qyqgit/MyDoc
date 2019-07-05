#include<stdio.h>
int main(){
    int a = 0;
    scanf("%d",&a);
    if(a > 0)
        printf("正数\n");
    else if(a < 0)
        printf("负数\n");
    else
        printf("零\n");
}
