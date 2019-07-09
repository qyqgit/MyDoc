//指针演示
#include<stdio.h>
int main(){
	int arr[] = {1, 2, 3, 4, 5};
	int *p_val = arr;
	for(int i = 0; i <= 4; i++){
		printf("%d\n", arr[i]);
		printf("%d\n", p_val[i]);
		printf("%d\n", *(arr + i));
		printf("%d\n", *(p_val + i));
	}
	return 0;
}
