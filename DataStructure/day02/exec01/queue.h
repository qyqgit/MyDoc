#ifndef __QUEUE_H__
#define __QUEUE_H__
#define SIZE 100
typedef struct {
	int buf[SIZE];
	int head;//记录队列里的第一个数字，如果没有数字，head等于tail
	int tail;//记录最后一个数字
} queue_t;
void queue_init(queue_t *p_queue);
void queue_deinit(queue_t *p_queue);
int queue_empty(const queue_t *p_queue);
int queue_full(const queue_t *p_queue);
int queue_size(const queue_t *p_queue);
int queue_push(queue_t *p_queue, int val);
int queue_pop(queue_t *p_queue, int *p_val);
int queue_front(const queue_t *p_queue, int *p_val);
#endif
