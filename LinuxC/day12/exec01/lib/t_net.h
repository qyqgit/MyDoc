/*
 * server.c
 *
 *  Created on: 2019年8月5日
 *      Author: vim
 */
#ifndef __T_NET_H__
#define __T_NET_H__
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <ctype.h>
typedef struct sockaddr SA;
typedef struct sockaddr_in SA4;
typedef struct sockaddr_in6 SA6;
int s_bind(int domain, int type, uint16_t port);
int mylisten(int port ,int linelen);
int h_accept(int socketfd);
#endif
