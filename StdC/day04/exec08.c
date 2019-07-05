#include<stdio.h>
int main(){
    int a = 0;
    int b = 0;
    int tmp = 0;
    scanf("%d", &a);
    scanf("%d", &b);
    while(b != 0){
        //if(b == 0){
        //    printf("%d\n",a);
        //    break;
        //}
        tmp = b;
        b = a % b;
        a = tmp;
    }
    printf("%d\n",a);
}
