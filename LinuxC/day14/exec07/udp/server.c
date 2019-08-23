#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <ctype.h>
int main(int argc, char *argv[]){
	char buf[128];
	struct sockaddr_in serv;
	struct sockaddr_in cli;
	serv.sin_family = AF_INET;
	serv.sin_port = htons(4466);
	serv.sin_addr.s_addr = htonl(INADDR_ANY);
	
	socklen_t len = sizeof(cli);

	strcpy(buf, "test msg.\n");
	int socketfd = socket(AF_INET, SOCK_DGRAM, 0);
	int status = bind(socketfd, (struct sockaddr*)&serv, sizeof(serv));
	while(1){
		int rcvsize = recvfrom(socketfd, buf, strlen(buf) + 1, 0, (struct sockaddr*)&cli, &len);//get msg from client
		for(int i = 0; i < rcvsize; i++){
			buf[i] = toupper(buf[i]);
		}
		sendto(socketfd, buf, rcvsize, 0, (struct sockaddr*)&cli, sizeof(cli));//send msg to client
	}
	close(socketfd);
	return 0;
}
