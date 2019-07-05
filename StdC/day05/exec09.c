#include<stdio.h>
int main(){
    int arr[5][5] = {0};
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(j == 2)
                arr[i][j] = 1;
            else if(i == 2)
                arr[i][j] = 2;
            else if(i == j)
                arr[i][j] = 3;
            else if(i == 4 - j)
                arr[i][j] = 4;
        }
    }
    arr[2][2] = 0;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}
