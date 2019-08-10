#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
typedef struct node{
	int data;
	struct node* next;
}node_t;
typedef node_t* list_t;

list_t head = NULL;//定义链表为空
pthread_mutex_t mutex;//定义mutex锁
pthread_cond_t cond;
//生产者线程
void *product(void *arg){
	node_t *new;
	while(1){
		//生产一个新的节点
		new = (node_t*)malloc(sizeof(node_t));
		new->data = rand() % 1000 + 1;
		new->next = NULL;
		printf("p:%d\n", new->data);
		//将新节点插入到链表头
		//加锁
		pthread_mutex_lock(&mutex);
		new->next = head;
		head = new;
		//解锁
		pthread_mutex_unlock(&mutex);
		//让临界条件变为真
		pthread_cond_signal(&cond);
		sleep(rand() % 3 + 1);

	}
	return NULL;
}
//消费者线程 受约束于链表为空
void *consume(void *arg){
	node_t *tmp;
	while(1){
		//加锁
		pthread_mutex_lock(&mutex);
		//从链表头部摘取一个节点
		while(head == NULL){
			//阻塞等待
			pthread_cond_wait(&cond, &mutex);
		}
		{
			//加锁??
			//pthread_mutex_lock(&mutex);
			tmp = head;
			head = head->next;
			//解锁
			pthread_mutex_unlock(&mutex);
			//消费摘取的节点
			printf("c:%d\n", tmp->data);
			free(tmp);
			tmp = NULL;
		}
		sleep(rand() % 3 + 1);
	}
	return NULL;

}
int main(int argc, char *argv[]){
	srand(time(NULL));
	pthread_mutex_init(&mutex, NULL);
	pthread_cond_init(&cond, NULL);

	pthread_t pid,cid;
	pthread_create(&pid, NULL, product, NULL);
	pthread_create(&cid, NULL, consume, NULL);
	
	pthread_join(pid, NULL);
	pthread_join(cid, NULL);

	pthread_mutex_destroy(&mutex);
	pthread_cond_destroy(&cond);

	return 0;
}
