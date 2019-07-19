#include <stdio.h>
#include "../day01/exec03/stack.h"
int main(){
	int val = 123456;
	int tmp = 0;
	int val2 = 0;
	stack_t stack;
	stack_init(&stack);
	while(val){
		tmp = val % 10;
		val /= 10;
		stack_push(&stack, tmp + '0');
	}
	while(stack.qty){
		stack_pop(&stack, &val2);
		printf("%c", val2);
	}
	printf("\n");

	
}
