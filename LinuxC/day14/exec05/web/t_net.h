#ifndef T_NET_H_
#define T_NET_H_
//#include <t_stdio.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <unistd.h>
#include <stdio.h>
#define E_MSG(STR,VAL) do{perror(STR);return(VAL);}while(0)

typedef struct sockaddr SA;
typedef struct sockaddr_in SA4;
typedef struct sockaddr_in6 SA6;
int s_bind(int domain,int type,uint16_t port);
int s_listen(int domain,int type,uint16_t port,int backlog);
//无来电显
int n_accept(int fd);
int h_accept(int fd);

#endif
