#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
int val = 0;

pthread_mutex_t mutex;
pthread_cond_t cond;

void *product(void *arg){
	int times = 50000000;
	while(times--){
		pthread_mutex_lock(&mutex);
		val++;
		printf("p:%07d\n", val);
		pthread_mutex_unlock(&mutex);
		
		pthread_cond_signal(&cond);
		
		//sleep(1);
	}
	
}

void *consume(void *arg){
	int times = 50000000;
	while(times--){
		pthread_mutex_lock(&mutex);
		if(val == 0){
		//while(val == 0){
			pthread_cond_wait(&cond, &mutex);
		}
		val--;
		printf("c:%07d\n", val);
		pthread_mutex_unlock(&mutex);
		//sleep(1);
	}
}
int main(int argc, char* argv[]){
	pthread_mutex_init(&mutex, NULL);
	pthread_cond_init(&cond, NULL);
	
	pthread_t pid, cid;
	pthread_create(&pid, NULL, product, NULL);
	pthread_create(&cid, NULL, consume, NULL);
	
	pthread_join(pid, NULL);
	pthread_join(cid, NULL);
	
	pthread_mutex_destroy(&mutex);
	pthread_cond_destroy(&cond);
	
	printf("%d\n", val);
	return 0;
}
