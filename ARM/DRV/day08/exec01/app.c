#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

//声明按键信息的数据结构
struct btn_event {
	int state; //按键状态
	int key_val; //键值
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
    
        //重复读取,而不是轮询
        while(1) {
            read(fd, &btn, sizeof(btn));
            printf("state:%s, code:%d\n",
                    btn.state?"release":"press", btn.key_val);
        }
	
        close(fd);
	return 0;
}


