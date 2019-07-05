#include<stdio.h>
int main(){
    int x = 0;
    int y = 0;
    for(int i = 1; i <= 40; i++){
        x = i;
        y = 40 - x;
        if(4 * x + 2 * y ==  100)
            printf("x=%d y=%d\n", x, y);
    }
}
