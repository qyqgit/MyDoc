#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
//定义环状队列类型
typedef int que_t[5];
que_t q;//定义一个环状队列
sem_t p, c;//定义两个信号量类型 生产数 消费数

void *cons(void *arg){
	int h = 0;//头
	int tmp;
	while(1){
		sem_wait(&c);
		tmp = q[h];
		q[h] = -1;
		h = (h + 1) % 5;
		sem_post(&p);
		printf("c:%d\n", tmp);
		sleep(rand() % 4 + 1);
	}
}

void *prod(void *arg){
	int w = 0;//尾
	while(1){
		sem_wait(&p);
		q[w] = rand() % 100 + 1;
		printf("p:%d\n", q[w]);
		w = (w + 1) % 5;
		sem_post(&c);
		sleep(rand() % 4 + 1);
	}
}


int main(){
	srand(time(NULL));
	sem_init(&p, 0, 5);
	sem_init(&c, 0, 0);

	pthread_t pid, cid;
	pthread_create(&pid, NULL, prod, NULL);
	pthread_create(&cid, NULL, cons, NULL);

	pthread_join(pid, NULL);
	pthread_join(cid, NULL);

	sem_destroy(&p);
	sem_destroy(&c);
	return 0;
}
