#include <stdio.h>
void swap(int **pp_a, int **pp_b){
	int *p_tmp = NULL;
	p_tmp = *pp_a;
	*pp_a = *pp_b;
	*pp_b = p_tmp;

}
int main(){
	int a = 3;
	int b = 7;
	int *p_a = &a;
	int *p_b = &b;
	swap(&p_a, &p_b);
	printf("%d %d\n", *p_a, *p_b);
	return 0;
}
