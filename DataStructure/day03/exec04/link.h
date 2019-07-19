#ifndef __LINK_H__
#define __LINK_H__
#include <stdlib.h>
typedef struct node {
	int val;
	struct node *p_next;
	struct node *p_prev;
} node_t;
typedef struct {
	node_t head;
	node_t tail;
} link_t;

void link_init(link_t *p_link);
void link_deinit(link_t *p_link);
int link_empty(const link_t *p_link);

int link_size(const link_t *p_link);
//在最后插入新数字
int link_append(link_t *p_link, int val);
int link_add_head(link_t *p_link, int val);
//按照从小到大的顺序把数字放入链表
int link_insert(link_t *p_link, int val);
int link_remove_tail(link_t *p_link);
int link_remove_head(link_t *p_link);
//删除中间某一个数字
int link_remove(link_t *p_link, int val);

int link_get_tail(const link_t *p_link, int *p_val);
int link_get_head(const link_t *p_link, int *p_val);
int link_get(const link_t *p_link, int sn, int *p_val);
#endif

