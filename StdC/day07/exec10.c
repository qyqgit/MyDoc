#include<stdio.h>
int* get_max(const int *p, int size){
	int *p_max = (int*)p;
	//const int *p_max = p;
	for(int i = 0; i < size; i++){
		if(*p_max < *(p + i)){
			p_max = (int*)p + i;
		}
	}
	return p_max;
}
int main(){
	int arr[] = {2333, 33, 5, 77, 333, 4, 5, 2, 7, 8, 33 , 5555};
	printf("%d\n", *get_max(arr, sizeof(arr) / sizeof(arr[0])));

}
