#include<stdio.h>
//void print(int *p_val, int size){
void print(const int *p_val, int size){//const 表示被调函数不会修改指针指向的值
	for(int i = 0; i < size; i++){
		printf("%d ", *(p_val + i));
	}
	printf("\n");
}
int main(){
	int arr[] = {1, 3 ,4 ,5 ,3 , 4, 5};
	print(arr, sizeof(arr) / sizeof(int));
	return 0;
}
