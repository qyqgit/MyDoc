#include <stdio.h>
int main(){
	int val = 0;
	int *p_val = &val;
	int **pp_val = &p_val;

	**pp_val = 10;
	printf("%d\n", val);
	*pp_val = NULL;
	printf("%p\n", p_val);
	printf("%d\n", val);
	//printf("%d\n", **pp_val);
	return 0;
}
