#include <stdio.h>
#include "stack.h"

void stack_init(stack_t *p_stack){
	p_stack->qty = 0;

}
void stack_deinit(stack_t *p_stack){
	p_stack->qty = 0;
}
int stack_empty(const stack_t *p_stack){
	return !p_stack->qty;
}
int stack_full(const stack_t *p_stack){
	return p_stack->qty >= SIZE;
}
int stack_size(const stack_t *p_stack){
	return p_stack->qty;
}
int stack_push(stack_t *p_stack, int val){
	if(p_stack->qty >= SIZE){
		return 0;
	}
	p_stack->buf[p_stack->qty] = val;
	p_stack->qty++;
	return 1;
	
}
int stack_pop(stack_t *p_stack, int *p_val){
	if(p_stack->qty <= 0){
		return 0;
	}
	*p_val = p_stack->buf[p_stack->qty - 1];
	p_stack->qty--;
	return 1;
}
int stack_top(const stack_t *p_stack, int *p_val){
	if(!p_stack->qty){
		return 0;
	}
	*p_val = p_stack->buf[p_stack->qty - 1];
	return 1;

}

