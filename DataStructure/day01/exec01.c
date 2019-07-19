#include <stdio.h>
typedef struct node{
	int val;
	struct node *p_next;
} node_t;
int main(){
	node_t head = {0};
	node_t node0 = {10};
	node_t node1 = {20};
	node_t node2 = {30};
	node_t tail = {0};
	node_t node4 = {25};

	node_t *p_tmp = NULL;
	node_t *p_first = NULL;
	node_t *p_mid = NULL;
	node_t *p_last = NULL;//third

	head.p_next = &node0;//init
	node0.p_next = &node1;//init
	node1.p_next = &node2;//init
	node2.p_next = &tail;//init
	for(p_tmp = &head; p_tmp != &tail; p_tmp = p_tmp->p_next){
		p_first = p_tmp;
		p_mid = p_first->p_next;
		p_last = p_mid->p_next;
		if(p_mid != &tail && p_mid->val == 20){
			p_first->p_next = p_last;
			break;
		}
	}

	for(p_tmp = &head; p_tmp != &tail; p_tmp = p_tmp->p_next){//insert
		p_first = p_tmp;
		p_mid = p_first->p_next;
		p_last = p_mid->p_next;
		if(p_mid == &tail || p_mid->val > node4.val){
			p_first->p_next = &node4;
			node4.p_next = p_mid;
			break;
			
		}
	}

	for(p_tmp = &head; p_tmp != &tail; p_tmp = p_tmp->p_next){// one by one
		p_first = p_tmp;
		p_mid = p_first->p_next;
		p_last = p_mid->p_next;
		if(p_mid != &tail){
			printf("%d ", p_mid->val);
		}
	}
	printf("\n");	
	return 0;
}
