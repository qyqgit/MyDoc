#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

struct btn_event{
	int state;
	int key_val;
};

int main(int argc, char *argv[]){
	int fd;
	struct btn_event btn;
	fd = open("/dev/mybtn", O_RDWR);
	if(fd < 0){
		printf("open btn device fail.");
		return -1;
	}
	while(1){
		read(fd, &btn, sizeof(btn));
		printf("state:%s, code:%d\n", btn.state? "release":"press", btn.key_val);
	}
	close(fd);
	return 0;
}
