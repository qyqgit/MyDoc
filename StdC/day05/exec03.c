#include<stdio.h>
int main(){
    int arr[5] = {0};
    for(int i = 0; i < 5; i++)
        arr[i] = i;
    for(int j = 4; j >= 0; j-- )
        printf("%d ", arr[j]);
    printf("\n");
}
