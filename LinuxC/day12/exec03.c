#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
void *func(void *arg){
	printf("arg..%s\t %d %lu\n", (char*)arg, getpid(), pthread_self());
	return NULL;
}
int main(void){
	pthread_t tid;
	printf("pthread_start\n");
	pthread_create(&tid, NULL, func, "new");
	printf("pthread_end\n");
	//sleep(1);
	func("main");
	return 0;
}
