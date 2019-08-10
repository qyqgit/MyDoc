#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <stdio.h>
#include "web.h"

char *web_dir="/home/tarena/html";

//接收客户端的请求信息，将这些请求信息保存
static void get_request(int fd,req_t *q){
    char buf[1024],path[128];
    int r=read(fd,buf,1024);
    sscanf(buf,"%s %s %s\r\n",q->method,q->path,q->proto);
    if(strcmp(q->path,"/")==0)strcpy(q->path,"/index.html");
    //将请求路径转换为服务器的本地路径
    strcpy(path,web_dir);
    strcat(path,q->path);
    strcpy(q->path,path);
    return;
}
char *get_ftyp(const char *file){
    char *f=strrchr(file,'.');
    if(f==NULL)return "text/html";
    if(strcmp(f,".jpg")==0)return "image/jpg";
    if(strcmp(f,".png")==0)return "image/png";
    return "text/html";
}
//查找客户端请求的文件是否可以被访问 200 404
//获取文件的类型   "text/html" "image/jpg" "image/png"
//文件的路径已经确定了
static void orgn_response(const char *file,res_t *s){
    s->code=access(file,R_OK)?404:200;
    s->f_type=get_ftyp(file);
    return;
}

static void response_b(int fd,req_t *rq,res_t *rs){
    char f_line[128];//  HTTP/1.1 200 \r\n
    sprintf(f_line,"%s %d\r\n",rq->proto,rs->code);
    char content[128];
    sprintf(content,"Content-Type: %s\r\n\r\n",rs->f_type);
    
    write(fd,f_line,strlen(f_line));
    write(fd,content,strlen(content));
    if(rs->code==404){
        char *html="<html><body><h2> page not found...!</body></html>";
        write(fd,html,strlen(html));
    }else{//200
        dup2(fd,1);
        execlp("cat","cat",rq->path,NULL);
    }
    return;
}

int t_main(int fd){
    req_t req; res_t res;
    //接收客户端的请求信息,将这些请求信息保存
    get_request(fd,&req);
    printf("method:%s\tpath:%s\tproto:%s\n",\
            req.method,req.path,req.proto);
    //处理客户端的请求信息，获取响应信息
    orgn_response(req.path,&res);
    printf("code:%d\tContent-type:%s\n",res.code,res.f_type);
    //根据响应信息，回应客户端
    response_b(fd,&req,&res);
    return 0;
}
