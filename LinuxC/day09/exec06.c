#include <stdio.h>
#include <unistd.h>
int main(void){
	alarm(5);
	for(int i = 1; i < 370000; i++){
		printf("i=%d\n", i);
	}
	int v = alarm(1);//取消之前闹钟，将上个闹钟的未决时间值存储到v中,并且设置1秒的闹钟，alarm(0)表示清除闹钟
	printf("v = %d\n", v);
#if 10
	for(int m = 1; m > 0; m++){
		printf("m = %d\n", m);
	}
#endif
	return 0;
}
