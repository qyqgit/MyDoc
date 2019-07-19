#include <stdio.h>
#include "stack.h"
int main(){
	int val = 0;
	stack_t stack;
	stack_init(&stack);
	printf("empty:%d\n", stack_empty(&stack));
	printf("full:%d\n", stack_full(&stack));
	printf("size:%d\n", stack.qty);
	stack_push(&stack, 1);
	stack_push(&stack, 2);
	stack_push(&stack, 3);
	stack_top(&stack, &val);
	printf("top:%d\n", val);
	stack_push(&stack, 4);
	printf("size:%d\n", stack.qty);
	stack_pop(&stack, &val);
	printf("%d\n", val);
	stack_pop(&stack, &val);
	printf("%d\n", val);
	stack_pop(&stack, &val);
	printf("%d\n", val);
	stack_pop(&stack, &val);
	printf("%d\n", val);
	printf("size:%d\n", stack.qty);
	stack_deinit(&stack);
}
