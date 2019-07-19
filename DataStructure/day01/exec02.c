#include <stdio.h>
#include <stdlib.h>
typedef struct node{
	int val;
	struct node *p_next;
} node_t;
int main(){
	int arr[] = {60, 30, 80, 10, 40, 20, 50, 70};
	node_t head = {0};
	node_t tail = {0};
	int num = 0;
	node_t *p_node = NULL;
	node_t *p_tmp = NULL;
	node_t *p_first = NULL;
	node_t *p_mid = NULL;
	node_t *p_last = NULL;

	head.p_next = &tail;
	for(num = 0; num <= 7; num++){
		p_node = (node_t*)malloc(sizeof(node_t));
		if(!p_node){
			continue;//break;
		}
		p_node->val = arr[num];
		p_node->p_next = NULL;
		for(p_tmp = &head; p_tmp != &tail; p_tmp = p_tmp->p_next){
			p_first = p_tmp;
			p_mid = p_first->p_next;
			p_last = p_mid->p_next;
			if(p_mid == &tail || p_mid->val > arr[num]){
				p_first->p_next = p_node;
				p_node->p_next = p_mid;
				break;
			}
		}
	}
	for(p_tmp = &head; p_tmp != &tail; p_tmp = p_tmp->p_next){
		p_first = p_tmp;
		p_mid = p_first->p_next;
		p_last = p_mid->p_next;
		if(p_mid != &tail){
			printf("%d\n", p_mid->val);
		}
	}
	while(head.p_next != &tail){
		//让三个指针指向最前面的三个节点
		p_first = &head;
		p_mid = p_first->p_next;//指向第一个有效节点
		p_last = p_mid->p_next;
		//把第一个有效节点从链式物理结构中摘除
		p_first->p_next = p_last;
		free(p_mid);
		p_mid = NULL;
	}
	for(p_tmp = &head; p_tmp != &tail; p_tmp = p_tmp->p_next){
		p_first = p_tmp;
		p_mid = p_first->p_next;
		p_last = p_mid->p_next;
		if(p_mid != &tail){
			printf("%d\n", p_mid->val);
		}
	}
	return 0;
}
