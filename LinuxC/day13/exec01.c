#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
void *thr_func(void *arg){
	printf("thread running\n");
	return (void*)1;	
}
void *thr_func2(void *arg){
	while(1){
		printf("thread2 running\n");
		sleep(1);
	}
}
int main(void){
	pthread_t tid;
	void *retval;
	pthread_create(&tid, NULL, thr_func, NULL);
	pthread_join(tid, &retval);
	printf("tid exit code %d\n", (int)retval);

	pthread_create(&tid, NULL, thr_func2, NULL);
	sleep(4);
	pthread_cancel(tid);
	printf("pthr2_cancel\n");
	pthread_join(tid, &retval);//阻塞等待
	printf("pthr2_join2\n");
	if(retval == PTHREAD_CANCELED){
		printf("thr_func2 exit code %d\n", (int) retval);
	}
	return 0;
}
