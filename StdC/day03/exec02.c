#include<stdio.h>
int main(){
    int a = 0;
    int b = 1;
    int index = 32;
    scanf("%d",&a);
    while(index > 0){
        index--;
        printf("%d",a >> index & b);
    }
    printf("\n");
}
