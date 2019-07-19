#ifndef __STACK_H__
#define __STACK_H__
#include <stdio.h>
#define	SIZE 100
typedef struct stack{
	int buf[SIZE];//记录栈里的数字，小下标记录前面的数字，大下标记录后面的数字
	int qty;//记录栈中的数字个数

} stack_t;

void stack_init(stack_t *p_stack);
void stack_deinit(stack_t *p_stack);
int stack_empty(const stack_t *p_stack);
int stack_full(const stack_t *p_stack);
int stack_size(const stack_t *p_stack);
int stack_push(stack_t *p_stack, int val);
int stack_pop(stack_t *p_stack, int *p_val);
int stack_top(const stack_t *p_stack, int *p_val);
#endif
