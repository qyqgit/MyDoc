#include<stdio.h>
int main(){
    for(int i = 0; i <= 10; i++ ){
        for(int j = 0; j <= 5; j++){
            for(int k = 0; k <= 2; k++){
                if(i + 2 * j + 5 * k == 10)
                    printf("i=%d j=%d k=%d\n", i, j, k);
            }
        }
    }
}
