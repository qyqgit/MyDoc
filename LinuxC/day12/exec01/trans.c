#include <unistd.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>
int t_main(int connectfd){
	char buf[128];
	while(1){
		int readsize = read(connectfd, buf, 128);//get msg from client
		for(int i = 0; i < readsize; i++){
			buf[i] = toupper(buf[i]);
		}
		printf("%s",buf);
		write(connectfd, buf, readsize);//send to client
		if(!strcmp("EXIT\n", buf)){
			printf("serv connect break\n");
			break;
		};	
	}
	return 0;

}
