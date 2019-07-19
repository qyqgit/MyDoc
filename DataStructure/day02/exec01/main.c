#include <stdio.h>
#include "queue.h"
int main(){
	int val = 0;
	queue_t que = {0};
	queue_init(&que);
	printf("empty:%d\n", queue_empty(&que));
	printf("full:%d\n", queue_full(&que));
	printf("size:%d\n", queue_size(&que));
	queue_push(&que, 10);
	queue_push(&que, 20);
	queue_push(&que, 30);
	queue_front(&que, &val);
	printf("top:%d\n", val);
	queue_pop(&que, &val);
	queue_pop(&que, &val);
	queue_front(&que, &val);
	printf("top:%d\n", val);
	queue_push(&que, 40);
	queue_push(&que, 50);
	queue_front(&que, &val);
	printf("top:%d\n", val);
	printf("empty:%d\n", queue_empty(&que));
	printf("full:%d\n", queue_full(&que));
	printf("size:%d\n", queue_size(&que));
	while(1){
		if(!queue_pop(&que, &val)){
			break;
		}
		printf("%d\n", val);
	}
	printf("\n");
	queue_deinit(&que);
	return 0;
}

