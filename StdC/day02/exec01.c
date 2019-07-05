#include<stdio.h>
int main(){
    int a = 10;
    int i = 1;
    while(a - i >= i){
        printf("%d * %d = %d\n", i, a - i, i * (a - i));
        i++;
    }
}


