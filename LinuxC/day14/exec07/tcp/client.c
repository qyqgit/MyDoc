/*
 * client.c
 *
 *  Created on: 2019年8月5日
 *      Author: vim
 */
#include <stdio.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <pthread.h>
char buf[256];
int socketfd;
void *product(void *arg){

	while(1){
		//printf("input:");
		fgets(buf, 256, stdin);
		write(socketfd, buf, strlen(buf));
	}
	
}
void *consume(void *arg){

	while(1){
		int readsize = read(socketfd, buf, 256);
		write(1, buf, readsize);
	}
	
}

int main(int argc, char *argv[]){

	struct sockaddr_in serv;
	serv.sin_family = AF_INET;
	serv.sin_port = htons(atoi(argv[2]));
	//inet_pton(AF_INET, "localhost", &serv.sin_addr);
	inet_pton(AF_INET, argv[1], &serv.sin_addr);
	socketfd = socket(AF_INET, SOCK_STREAM, 0);
	if(socketfd == -1){
		perror("socket");
		return -1;
	}
	int status = connect(socketfd, (struct sockaddr*)&serv, sizeof(serv));
	if(status == -1){
		perror("connect");
		return -1;
	}
	pthread_t pid, cid;
	pthread_create(&pid, NULL, product, NULL);
	pthread_create(&cid, NULL, consume, NULL);
	
	pthread_join(pid, NULL);
	pthread_join(cid, NULL);
	close(socketfd);
}

