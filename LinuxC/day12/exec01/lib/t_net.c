/*
 * server.c
 *
 *  Created on: 2019年8月5日
 *      Author: vim
 */
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <ctype.h>
#include "t_net.h"
int s_bind(int domain, int type, uint16_t port){
	SA4 serv;//ipv4具体地址
	serv.sin_family = AF_INET;
	serv.sin_port = htons(port);
	serv.sin_addr.s_addr = htonl(INADDR_ANY);
	int socketfd = socket(domain, type, 0);
	if(socketfd == -1){
		perror("socket");
		return -1;
	}
	int b = bind(socketfd, (SA*)&serv, sizeof(serv));
	if(b == -1){
		perror("bind");
		return -1;
	}

	return socketfd;
}
int mylisten(int port ,int linelen){
	int socketfd = s_bind(AF_INET, SOCK_STREAM, port);
	listen(socketfd, linelen);
	return socketfd;
}
int h_accept(int socketfd){
	SA4 cli_addr;
	socklen_t cli_len = sizeof(cli_addr);
	char ip[INET_ADDRSTRLEN];
	int connectfd = accept(socketfd, (SA*)&cli_addr, &cli_len);
	if(connectfd == -1){
		perror("accept");
		return -1;
	}

	inet_ntop(AF_INET, &cli_addr.sin_addr, ip, INET_ADDRSTRLEN);
	printf("%s\n", ip);
	return connectfd;
}
