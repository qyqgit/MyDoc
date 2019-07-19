#include <stdio.h>
#include <stdlib.h>
typedef struct node {
	int val;
	struct node *p_next;
} node_t;
typedef struct {
	node_t head;
	node_t tail;
} link_t;

void link_init(link_t *p_link){
	p_link->head.p_next = &p_link->tail;
	p_link->tail.p_next = NULL;
}
void link_deinit(link_t *p_link){
	/*node_t *p_first = NULL;
	node_t *p_mid = NULL;
	node_t *p_last = NULL;
	node_t *p_tmp = NULL; 
	for(p_tmp = &p_link->head; p_tmp != &p_link->tail; p_tmp = p_tmp->p_next){
		p_first = p_tmp;
		p_mid = p_first->p_next;
		p_last = p_mid->p_next;
		if(p_mid != *p_link->tail)
			free(p_mid);
	}
	p_link->tail = 0;*/
	node_t *p_first = NULL;
	node_t *p_mid = NULL;
	node_t *p_last = NULL;
	while(p_link->head.p_next != &p_link->tail){//头节点后面不是尾节点就表示存在有效节点，循环应该继续
		p_first = &p_link->head;
		p_mid = p_first->p_next;//指向第一个有效的节点
		p_last = p_mid->p_next;
		//把p_mid指针指向的节点从链式物理结构中摘除
		p_first->p_next = p_last;
		free(p_mid);
		p_mid = NULL;
	}
}
int link_empty(const link_t *p_link){
	return p_link->head.p_next == &p_link->tail;
}

int link_size(const link_t *p_link){
	int cnt = 0;
	const node_t *p_tmp = NULL;
	const node_t *p_first = NULL, *p_mid = NULL, *p_last = NULL;
	for(p_tmp = &p_link->head; p_tmp != &p_link->tail; p_tmp = p_tmp->p_next){
		p_first = p_tmp;
		p_mid = p_first->p_next;
		p_last = p_mid->p_next;
		if(p_mid != &p_link->tail){
			cnt++;
		}
	}
	return cnt;
}
//在最后插入新数字
int link_append(link_t *p_link, int val){
	node_t *p_node = NULL;
	node_t *p_tmp = NULL;
	node_t *p_first = NULL;
	node_t *p_mid = NULL;
	node_t *p_last = NULL;
	p_node = (node_t*)malloc(sizeof(node_t));
	if(!p_node){
		return 0;
	}
	//填充动态分配节点的内容
	p_node->val = val;
	p_node->p_next = NULL;
	for(p_tmp = &p_link->head; p_tmp != &p_link->tail; p_tmp = p_tmp->p_next){
		p_first = p_tmp;
		p_mid = p_first->p_next;
		p_last = p_mid->p_next;
		if(p_mid == &p_link->tail){
			//p_mid指针指向尾节点时p_first和p_mid中间就是最后的位置
			p_first->p_next = p_node;
			p_node->p_next = p_mid;
			break;
		}
		
	}


}
int link_add_head(link_t *p_link, int val){
	node_t *p_node = NULL;
	node_t *p_first = NULL, *p_mid = NULL, *p_last = NULL;
	p_node = (node_t*)malloc(sizeof(node_t));
	if(!p_node){
		return 0;
	}
	//向动态分配节点中填充内容
	p_node->val = val;
	p_node->p_next = NULL;
	//找到头节点后面的位置插入
	//把三个指针指向链表最前面三个节点
	p_first = &p_link->head;
	p_mid = p_first->p_next;
	p_last = p_mid->p_next;
	//把新节点插入到p_first和p_mid中间
	p_first->p_next = p_node;
	p_node->p_next = p_mid;
	return 1;
	
}
//按照从小到大的顺序把数字放入链表
int link_insert(link_t *p_link, int val){
	node_t *p_node = NULL, *p_tmp = NULL;
	node_t *p_first = NULL, *p_mid = NULL, *p_last = NULL;
	p_node = (node_t*)malloc(sizeof(node_t));
	if(!p_node){
		return 0;
	}
	p_node->val = val;
	p_node->p_next = NULL;
	//用for循环找到要插入的位置
	for(p_tmp = &p_link->head; p_tmp != &p_link->tail; p_tmp = p_tmp->p_next){
		p_first = p_tmp;
		p_mid = p_first->p_next;
		p_last = p_mid->p_next;
		if(p_mid == &p_link->tail || p_mid->val > val){//p_mid指针指向尾节点或p_mid指针指向节点里的数字比新数字大
			p_first->p_next = p_node;
			p_node->p_next = p_mid;
			break;
		}
	}
	return 1;
}
int link_remove_tail(link_t *p_link){
	node_t *p_tmp = NULL;
	node_t *p_first = NULL, *p_mid = NULL, *p_last = NULL;
	for(p_tmp = &p_link->head; p_tmp != &p_link->tail; p_tmp = p_tmp->p_next){
		p_first = p_tmp;
		p_mid = p_first->p_next;
		p_last = p_mid->p_next;
		if(p_last == &p_link->tail){//p_last指针指向尾节点时p_mid指针指向最后一个有效节点
			p_first->p_next = p_last;
			free(p_mid);
			p_mid = NULL;
			return 1;
		}
	}
	return 0;
}
int link_remove_head(link_t *p_link){
	node_t *p_first = NULL, *p_mid = NULL, *p_last = NULL;
	if(p_link->head.p_next == &p_link->tail){//如果没有节点
		return 0;
	}
	p_first = &p_link->head;
	p_mid = p_first->p_next;
	p_last =p_mid->p_next;
	//把p_mid指针指向的节点从链表里摘除
	p_first->p_next = p_last;
	free(p_mid);
	p_mid = NULL;
	return 1;
}
//删除中间某一个数字
int link_remove(link_t *p_link, int val){
	node_t *p_tmp = NULL;
	node_t *p_first = NULL, *p_mid = NULL, *p_last = NULL;
	for(p_tmp = &p_link->head; p_tmp != &p_link->tail; p_tmp = p_tmp->p_next){
		p_first = p_tmp;
		p_mid = p_first->p_next;
		p_last = p_mid->p_next;
		if(p_mid != &p_link->tail && p_mid->val == val){
			p_first->p_next = p_last;
			free(p_mid);
			p_mid = NULL;
			return 1;
		}
	}
	return 0;
}

int link_get_tail(const link_t *p_link, int *p_val){
	const node_t *p_tmp = NULL;
	const node_t *p_first = NULL, *p_mid = NULL, *p_last = NULL;
	for(p_tmp = &p_link->head; p_tmp != &p_link->tail; p_tmp = p_tmp->p_next){
		p_first = p_tmp;
		p_mid = p_first->p_next;
		p_last = p_mid->p_next;
		/*if(p_mid == &p_link->tail)
			return p_first->val;*/
		if(p_last == &p_link->tail){
			*p_val = p_mid->val;
			return 1;
		}
	}
	return 0;

}
int link_get_head(const link_t *p_link, int *p_val){
	const node_t *p_first = NULL, *p_mid = NULL, *p_last = NULL;
	if(p_link->head.p_next == &p_link->tail){
		//头节点后面就是尾节点表示没有有效节点
		return 0;
	}
	//让三个指针指向最前面的三个节点
	p_first = &p_link->head;
	p_mid = p_first->p_next;
	p_last = p_mid->p_next;
	*p_val = p_mid->val;
	return 1;
}
int link_get(const link_t *p_link, int sn, int *p_val){
	int cnt = 0;
	const node_t *p_tmp = NULL;
	const node_t *p_first = NULL, *p_mid = NULL, *p_last = NULL;
	for(p_tmp = &p_link->head; p_tmp != &p_link->tail; p_tmp = p_tmp->p_next){
		p_first = p_tmp;
		p_mid = p_first->p_next;
		p_last = p_mid->p_next;
		//cnt就是p_mid指针指向节点的编号
		if(p_mid != &p_link->tail && cnt == sn){
			//p_mid指针指向的节点不是尾节点且这个节点的编号就是参指定的编号
			*p_val = p_mid->val;
			return 1;	
		}
		cnt++;
	}

}











