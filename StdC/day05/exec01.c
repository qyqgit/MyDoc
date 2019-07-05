#include<stdio.h>
int main(){
    int a = 0;
    int b = 0;
    scanf("%d", &a);
    printf("a=%d\n", a);
    //
    scanf("%*[^\n]");
    scanf("%*c");
    //
    scanf("%d", &b);
    printf("b=%d\n", b);
}
