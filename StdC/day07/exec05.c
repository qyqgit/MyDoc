#include<stdio.h>
int main(){
	int val = 0;
	const int *p_val = &val;
	int * const p_val1 = &val;
	int const *p_val2 = &val;
	//*p_val = 10; error
	p_val = NULL;
	*p_val1 = 10;
	//p_val1 = NULL; error
	//*p_val2 = 10; error
	p_val2 = NULL;
	return 0;
}
