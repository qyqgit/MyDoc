#include <unistd.h>
#include <t_net.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>

void handle(int n){
    wait(NULL);
    return;
}

extern int t_main(int);
int main(void){
    signal(SIGCHLD,handle);
    //创建一个通讯端点，返回该设备的文件描述符
    int sfd=s_listen(AF_INET,SOCK_STREAM,3344,5);
    if(sfd==-1)return -1;
    while(1){
        int cfd=h_accept(sfd);
        if(cfd==-1)return -1;
        //连接好之后，再创建子进程
        pid_t pid=fork();
        if(pid==-1)E_MSG("fork",-1);
        if (pid==0){
            close(sfd);
            t_main(cfd);
            close(cfd);//关闭本次连接
            exit(0);
        }else{
            close(cfd);
            //waitpid(-1,NULL,WNOHANG);//阻塞等待子进程的终止

        }
    }
    return 0;
}
