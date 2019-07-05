#include<stdio.h>
int main(){
    int a = 0;
    int b = 0;
    int c = 0;
    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&c);
    printf("%d\n",(a > b ? a = b : a) > c ? c : a );
}
