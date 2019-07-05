#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void create(int arr[], int size){
    int num = 0;
    for(num = 0; num <= size -1; num++){
        arr[num] = rand() % 36 + 1;
    }
}
void show(int arr[], int size){
    int num = 0;
    for(num = 0; num < size; num++){
        printf("%d ", arr[num]);
    }
    printf("\n");
}
int main(){
    int arr[7] = {0};
    srand(time(0));
    create(arr, 7);
    show(arr, 7);
    return 0;
}
