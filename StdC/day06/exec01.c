#include<stdio.h>
int fun(int x, int y){
    printf("%d * %d = %d\n", x, y, x * y);
}
int main(){
    for(int x = 1; x <=5; x++){
        fun(x, 10 - x);
    }
}
