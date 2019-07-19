#include <stdio.h>
#include "queue.h"
#define SIZE 100

void queue_init(queue_t *p_queue){
	p_queue->head = 0;
	p_queue->tail = 0;
}
void queue_deinit(queue_t *p_queue){
	p_queue->head = 0;
	p_queue->tail = 0;
}
int queue_empty(const queue_t *p_queue){
	return p_queue->head == p_queue->tail;
}
int queue_full(const queue_t *p_queue){
	return p_queue->tail >= SIZE;
}
int queue_size(const queue_t *p_queue){
	return p_queue->tail - p_queue->head;
}
int queue_push(queue_t *p_queue, int val){
	if(p_queue->tail >= SIZE){
		return 0;
	}
	p_queue->buf[p_queue->tail] = val;
	p_queue->tail++;
	return 1;
}
int queue_pop(queue_t *p_queue, int *p_val){
	if(p_queue->head == p_queue->tail){
		return 0;
	}
	*p_val = p_queue->buf[p_queue->head];
	p_queue->head++;
	return 1;
}
int queue_front(const queue_t *p_queue, int *p_val){
	if(p_queue->head == p_queue->tail){
		return 0;
	}
	*p_val = p_queue->buf[p_queue->head];
	return 1;

	
}
