#include "queue.h"
//获得最前面数字所在存储区下标
int get_head(const queue_t *p_queue){
	int head = p_queue->tail - p_queue->qty;
	if(head < 0){
		//计算结果是负数就需要调整
		head += SIZE;
	}
	return head;
}
void queue_init(queue_t *p_queue){
	p_queue->tail = 0;
	p_queue->qty = 0;
}
void queue_deinit(queue_t *p_queue){
	p_queue->tail = 0;
	p_queue->qty = 0;
}
int queue_empty(const queue_t *p_queue){
	return !p_queue->qty;
}
int queue_full(const queue_t *p_queue){
	return p_queue->qty >= SIZE;
}
int queue_size(const queue_t *p_queue){
	return p_queue->qty;
}

int queue_push(queue_t *p_queue, int val){
	if(p_queue->tail >= SIZE ){
		return 0;
	}
	p_queue->buf[p_queue->tail] = val;
	p_queue->tail++;
	p_queue->qty++;
	if(p_queue->tail >= SIZE){
		p_queue->tail = 0;	
	}
	return 1;
}
int queue_pop(queue_t *p_queue, int *p_val){
	if(!p_queue->qty){
		return 0;
	}
	*p_val = p_queue->buf[get_head(p_queue)];
	p_queue->qty--;//删除数字
	return 1;
}
int queue_front(const queue_t *p_queue, int *p_val){
	if(!p_queue->qty){
		return 0;
	}
	*p_val = p_queue->buf[get_head(p_queue)];
	return 1;
}
