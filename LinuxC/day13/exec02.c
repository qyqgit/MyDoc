#include <stdio.h>
#include <pthread.h>
int val = 0;
//定义一把锁，这个锁被两个线程共享
//pthread_mutex_t mutex;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
void *thr_func(void *arg){
	int local_val;
	//加不好的锁
	//pthread_mutex_lock(&mutex);
	for(int i = 0; i < 500000; i++){
		//加锁
		pthread_mutex_lock(&mutex);
		local_val = val;
		local_val++;
		printf("local_val:%07d %lu\n",local_val, pthread_self());
		//printf("local_val:%07d\n",local_val);
		val = local_val;
		//解锁
		pthread_mutex_unlock(&mutex);
	}
	//解不好的锁
	//pthread_mutex_unlock(&mutex);
	return NULL;
}
int main(){
	pthread_t tid, cid;
	//初始化锁
	//pthread_mutex_init(&mutex, NULL);
	pthread_create(&tid, NULL, thr_func, NULL);
	pthread_create(&cid, NULL, thr_func, NULL);
	pthread_join(tid, NULL);
	pthread_join(cid, NULL);
	//销毁锁
	pthread_mutex_destroy(&mutex);
	printf("val:%d\n", val);
}
