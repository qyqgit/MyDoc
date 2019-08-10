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
#include "trans.h"
int main(int argc, char *argv[]){
	int socketfd = mylisten(4433, 5);

	while(1){
		int connectfd = h_accept(socketfd);
		t_main(connectfd);
		close(connectfd);
	}
	return 0;
}

