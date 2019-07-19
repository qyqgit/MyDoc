#include <stdio.h>
#define	SIZE 100
typedef struct stack{
	int buf[SIZE];//记录栈里的数字，小下标记录前面的数字，大下标记录后面的数字
	int qty;//记录栈中的数字个数

} stack_t;

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

