#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
int val = 0;

sem_t p, c;//定义两个信号量类型 生产数 消费数
pthread_mutex_t mutex;
pthread_cond_t cond;

void *product(void *arg){
	int times = 50000000;
	while(times--){
		sem_wait(&p);
		pthread_mutex_lock(&mutex);
		val++;
		sem_post(&c);
		printf("p:%07d\n", val);
		pthread_mutex_unlock(&mutex);
		
		pthread_cond_signal(&cond);
		
		//sleep(1);
	}
	
}

void *consume(void *arg){
	int times = 50000000;
	while(times--){
		sem_wait(&c);
		pthread_mutex_lock(&mutex);
		if(val == 0){
		//while(val == 0){
			pthread_cond_wait(&cond, &mutex);
		}
		val--;
		sem_post(&p);
		printf("c:%07d\n", val);
		pthread_mutex_unlock(&mutex);
		//sleep(1);
	}
}
int main(int argc, char* argv[]){
	sem_init(&p, 0, 99);
	sem_init(&c, 0, 0);

	pthread_mutex_init(&mutex, NULL);
	pthread_cond_init(&cond, NULL);
	
	pthread_t pid, cid;
	pthread_create(&pid, NULL, product, NULL);
	pthread_create(&cid, NULL, consume, NULL);
	
	pthread_join(pid, NULL);
	pthread_join(cid, NULL);
	
	pthread_mutex_destroy(&mutex);
	pthread_cond_destroy(&cond);
	
	sem_destroy(&p);
	sem_destroy(&c);
	
	printf("%d\n", val);
	return 0;
}
