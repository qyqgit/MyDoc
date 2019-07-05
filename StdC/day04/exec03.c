#include<stdio.h>
int main(){
    int a = 10;
    for(int i = 1; i <= a / 2; i++){
        printf("%d * %d = %d\n", i, a - i, i * (a - i));
    }
}
