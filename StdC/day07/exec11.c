#include<stdio.h>
void swap_arr(int *p, int size){
	int tmp = 0;
	for(int i = size - 1; i >= size - i; i--){
		tmp = *(p + i);
		*(p + i) = *(p + (size - 1 - i));
		*(p + (size - 1 -i)) = tmp;

	}
}
int main(){
	int arr[] = {0, 1, 2, 4, 2, 45, 6, 3, 3};
	swap_arr(arr, sizeof(arr) / sizeof(arr[0]));
	for(int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}
