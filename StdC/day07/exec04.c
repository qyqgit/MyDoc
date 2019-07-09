#include<stdio.h>
int main(){
	int arr[] = {1, 2, 3, 4, 5};
	int *p_val = NULL;
	for(p_val = arr; p_val <= arr + 4; p_val++){
		printf("%d\n", *p_val);
	}
}
