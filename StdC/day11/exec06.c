#include <stdio.h>
typedef void (*p_func_print_t)(int *);
void print(const int *p_val, int size){
	int num = 0;
	for(num = 0; num <= size -1; num++){
		printf("%d ", *(p_val + num));
	}
	printf("\n");

}
void neg_cb(int *p_val){
	*p_val = 0 - *p_val;

}
void print_cb(int *p_val){
	printf("%d ", *p_val);
}
void for_each(int *p_val, int size, p_func_print_t p_func){
	//void (*p_func_print)(int *) = print_cb;
	p_func_print_t p_func_print = p_func;
	int i = 0;
	for(i = 0; i < size; i++){
		p_func_print(p_val + i);

	}

}
int main(){
	int arr[] = {1, 2, 3, 4, 5};
	print(arr, 5);
	for_each(arr, 5, print_cb);
	printf("\n");

	for_each(arr, 5, neg_cb);
	for_each(arr, 5, print_cb);
	printf("\n");
	return 0;
}
