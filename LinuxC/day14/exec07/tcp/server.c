#include <netinet/in.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <fcntl.h>
int main(int argc, char *argv[]){
	char buf[256];
	struct sockaddr_in serv;
	serv.sin_family = AF_INET;
	serv.sin_addr.s_addr = htonl(INADDR_ANY);
	serv.sin_port = htons(atoi(argv[1]));

	struct sockaddr_in cli_addr;
	socklen_t cli_len = sizeof(cli_addr);
	char cli_ip[INET_ADDRSTRLEN];

	int socketfd = socket(AF_INET, SOCK_STREAM, 0);
	if(socketfd == -1){
		perror("socket");
		return -1;
	}
	int status = bind(socketfd, (struct sockaddr*)&serv, sizeof(serv));
	if(status == -1){
		perror("bind");
		return -1;
	}
	status = listen(socketfd, 5);
	if(status == -1){
		perror("listen");
		return -1;
	}

	int connectfd = accept(socketfd, (struct sockaddr*)&cli_addr, &cli_len);
	if(connectfd == -1){
		perror("accept");
		return -1;
	}
	inet_ntop(AF_INET, &cli_addr.sin_addr.s_addr, cli_ip, INET_ADDRSTRLEN);
	printf("%s:\n", cli_ip);
	int flags = fcntl(socketfd, F_GETFL, 0);
	flags |= O_NONBLOCK;
	fcntl(socketfd, F_SETFL, flags);
	while(1){

		int readsize = read(connectfd, buf, 256);
		buf[readsize] = '\0';
		printf("%s",buf);
		printf("input:");
		fgets(buf, 256, stdin);
		write(connectfd, buf, strlen(buf));
		
	}
	close(connectfd);
	close(socketfd);
	return 0;
}
