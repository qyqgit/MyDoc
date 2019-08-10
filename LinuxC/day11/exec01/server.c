/*
 * server.c
 *
 *  Created on: 2019年8月5日
 *      Author: vim
 */
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <ctype.h>
int main(int argc, char *argv[]){
	char buf[128];
	//struct sockaddr serv;
	struct sockaddr_in serv;//ipv4具体地址
	serv.sin_family = AF_INET;
	serv.sin_port = htons(4433);
	serv.sin_addr.s_addr = htonl(INADDR_ANY);
	int socketfd = socket(AF_INET, SOCK_STREAM, 0);
	if(socketfd == -1){
		perror("socket");
		return -1;
	}
	int b = bind(socketfd, (struct sockaddr*)&serv, sizeof(serv));
	if(b == -1){
		perror("bind");
		return -1;
	}
	listen(socketfd, 5);

	struct sockaddr_in cli_addr;
	socklen_t cli_len = sizeof(cli_addr);
	char ip[INET_ADDRSTRLEN];

	while(1){
		int connectfd = accept(socketfd, (struct sockaddr*)&cli_addr, &cli_len);
		if(connectfd == -1){
			perror("accept");
			return -1;
		}

		inet_ntop(AF_INET, &cli_addr.sin_addr, ip, INET_ADDRSTRLEN);
		printf("%s\n", ip);

		int readsize = read(connectfd, buf, 128);
		for(int i = 0; i < readsize; i++){
			buf[i] = toupper(buf[i]);
		}
		write(connectfd, buf, readsize);
		close(connectfd);
	}
	return 0;
}

