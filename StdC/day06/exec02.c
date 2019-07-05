#include<stdio.h>
void fun(int arr[], int size){
    int len = size;// sizeof(arr) / sizeof(arr[0]);
    int index = 0;
    for(index = 0; index < len; index++){
        printf("%d ", arr[index]);
    }
    printf("\n");
}
int main(){
    int arr[] = {1,2,3,4,5,6,11,22};
    printf("%d\n",sizeof(arr));
    fun(arr, sizeof(arr) / sizeof(arr[0]));
    return 0;
}
