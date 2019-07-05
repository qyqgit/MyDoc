#include<stdio.h>
int fun(int a){
    if(a == 1){
         return 1;
    }
    return  fun(a - 1) + a;

}
int main(){
    printf("%d\n", fun(100));

}
