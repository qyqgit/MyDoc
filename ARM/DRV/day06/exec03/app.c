#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

//声明按键信息的数据结构
struct btn_event {
	int state; //按键状态
	int code; //键值
};

int main(void)
{
	int fd;
	struct btn_event btn; //保存按键信息

	fd = open("/dev/mybtn", O_RDWR);
	if(fd < 0) {
		printf("open btn device failed.\n");
		return -1;
	}

	//轮询读取按键状态
	while(1) {
		read(fd, &btn, sizeof(btn));
		printf("state:%d, code:%d\n",btn.state, btn.code);
	}
	
	close(fd);
	return 0;
}
