#include "t_net.h"

//socket  bind
int s_bind(int domain,int type,uint16_t port){
    SA4 serv;
    //创建一个通讯端点，返回该设备的文件描述符
    int fd=socket(domain,type,0);
    if(fd==-1)E_MSG("socket",-1);
    //初始化serv成员
    serv.sin_family=AF_INET;
    serv.sin_port=htons(port);
    serv.sin_addr.s_addr=htonl(INADDR_ANY);
    //将本地地址和端口号绑定到sfd
    int b=bind(fd,(SA *)&serv,sizeof(serv));
    if(b==-1)E_MSG("bind",-1);
     
    return fd;
}

//s_bind  listen
int s_listen(int domain,int type,uint16_t port,int backlog){
    int fd=s_bind(domain,type,port);
    if(fd==-1) return -1;
    listen(fd,backlog);
    return fd;
}
//无来电显
int n_accept(int fd){
    int cfd=accept(fd,NULL,NULL);
    if(cfd==-1)E_MSG("accept",-1);
    return cfd;
}
//有来电显示
int h_accept(int fd){
    SA4 cli;
    char IP[32];
    socklen_t len=sizeof(SA4);
    int cfd=accept(fd,(SA *)&cli,&len);
    if(cfd==-1)E_MSG("accept",-1);
    printf("%s\n",inet_ntop(AF_INET,&cli.sin_addr,IP,32));
    return cfd;
}
