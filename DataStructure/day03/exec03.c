#include <stdio.h>
#include <string.h>
#include "../day01/exec03/stack.h"
int main(){
	//char arr[] = "+5-3*7+6/2";
	//char arr[] = "-5+3/7+6*2";
	//char arr[] = "-7-7*6-5";
	//char arr[] = "+4+5*2";
	//char arr[] = "-6+4";
	//char arr[] = "+4*3";
	//char arr[] = "-3*2";
	//char arr[] = "+8";
	char arr[] = "-9";
	int len = 0;
	stack_t stack;
	len = strlen(arr);
	stack_init(&stack);
	int ret = 0;
	int val = 0;
	int i = 0;
	int signe = 0;
	while(i < len){
		if('0'<= arr[i] && arr[i] <= '9')
			stack_push(&stack, arr[i] - '0');
		else{
			if(arr[i] == '*'){
				stack_pop(&stack, &val);
				stack_push(&stack, val * (arr[++i] - '0'));
			}else if(arr[i] == '/'){
				stack_pop(&stack, &val);
				stack_push(&stack, val / (arr[++i] - '0'));
			}else if(arr[i] == '+' || arr[i] == '-'){
				stack_push(&stack, arr[i]);
			}

		}
		i++;
	}
	i = 0;
	len = stack_size(&stack) / 2;
	while(i < len){
		stack_pop(&stack, &val);
		stack_pop(&stack, &signe);
		if(signe == '-')
			val = 0 - val;
		ret += val;
		i++;
	}
	printf("%d\n", ret);
	return 0;
}
