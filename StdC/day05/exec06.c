#include<stdio.h>
int main(){
    int arr[3][2];
    int n = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 2; j++){
            arr[i][j] = n;
            n++;
        }
    }

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 2; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("%p\n", arr);
    printf("%p\n", &arr[0][0]);
    printf("%p\n", arr[1]);
    printf("%p\n", &arr[1][0]);
    printf("sizeof(arr[1]):%d\n", sizeof(arr[1]));
}
