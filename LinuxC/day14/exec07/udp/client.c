#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
int main(int argc, char *argv[]){
	char buf[128];
	char *msg = "test msg.\n";
	struct sockaddr_in serv;
	serv.sin_family = AF_INET;
	serv.sin_port = htons(4466);
	inet_pton(AF_INET, "127.0.0.1", &serv.sin_addr);
	
	int fd = socket(AF_INET, SOCK_DGRAM, 0);
	int status = sendto(fd, msg, strlen(msg) + 1, 0, (struct sockaddr*)&serv, sizeof(serv));
	int rcvsize = recvfrom(fd, buf, 128, 0, NULL, NULL);
	write(1, buf, rcvsize);
	close(fd);
}
