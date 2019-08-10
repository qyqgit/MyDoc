/*
 * client.c
 *
 *  Created on: 2019年8月5日
 *      Author: vim
 */
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
int main(int argc, char *argv[]){
	char buf[128];
	char msg[128];
	//struct sockaddr serv;
	struct sockaddr_in serv;
	serv.sin_family = AF_INET;
	serv.sin_port = htons(4433);
	inet_pton(AF_INET, "127.0.0.1", &serv.sin_addr);
	int socketfd = socket(AF_INET, SOCK_STREAM, 0);
	if(socketfd == -1){
		perror("socket");
		return -1;
	}
	int c = connect(socketfd, (struct sockaddr*)&serv, sizeof(serv));
	if(c == -1){
		perror("connect");
		return -1;
	}
	while(1){
		printf("-");
		fgets(msg, 128, stdin);
		write(socketfd, msg, strlen(msg) + 1);//send to serv
		int readsize = read(socketfd, buf, 128);//get msg from serv
		if(!strcmp("EXIT\n", buf)){
			printf("client break\n");
			break;
		}
		write(1, buf, readsize);
	}
	close(socketfd);
}
