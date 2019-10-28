#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

//����������Ϣ�����ݽṹ
struct btn_event {
	int state; //����״̬
	int code; //��ֵ
};

int main(void)
{
	int fd;
	struct btn_event btn; //���水����Ϣ

	fd = open("/dev/mybtn", O_RDWR);
	if(fd < 0) {
		printf("open btn device failed.\n");
		return -1;
	}

	//��ѯ��ȡ����״̬
	while(1) {
		read(fd, &btn, sizeof(btn));
		printf("state:%d, code:%d\n",btn.state, btn.code);
	}
	
	close(fd);
	return 0;
}
