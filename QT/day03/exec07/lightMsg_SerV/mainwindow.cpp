#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

#include <netinet/in.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <pthread.h>

#define PORT_NUM 2233

char buf_get[256];
char buf_set[256];
int connectfd;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->init();
    clock = startTimer(100);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::init(){
    pthread_t mid;
    pthread_create(&mid, NULL, main_serv, NULL);
}
void* MainWindow::main_serv(void*){

    struct sockaddr_in serv;
    serv.sin_family = AF_INET;
    serv.sin_addr.s_addr = htonl(INADDR_ANY);
    serv.sin_port = htons(PORT_NUM);

    struct sockaddr_in cli_addr;
    socklen_t cli_len = sizeof(cli_addr);
    char cli_ip[INET_ADDRSTRLEN];

    int socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if(socketfd == -1){
        perror("socket");
        return (void*)-1;
    }
    int status = bind(socketfd, (struct sockaddr*)&serv, sizeof(serv));
    if(status == -1){
        perror("bind");
        return (void*)-1;
    }
    status = listen(socketfd, 5);
    if(status == -1){
        perror("listen");
        return (void*)-1;
    }

    connectfd = accept(socketfd, (struct sockaddr*)&cli_addr, &cli_len);
    if(connectfd == -1){
        perror("accept");
        return (void*)-1;
    }
    inet_ntop(AF_INET, &cli_addr.sin_addr.s_addr, cli_ip, INET_ADDRSTRLEN);
    printf("%s\n", cli_ip);
    pthread_t pid, cid;
    pthread_create(&pid, NULL, product, NULL);
    pthread_create(&cid, NULL, consume, NULL);

    pthread_join(pid, NULL);
    pthread_join(cid, NULL);
    ::close(connectfd);
    ::close(socketfd);
    return (void*)0;
}
void* MainWindow::product(void*){
    while(1){
        int readsize = read(connectfd, buf_get, 255);
        buf_get[readsize] = '\0';
        qDebug() << strlen(buf_get) << " strlen read serv\n";
        qDebug() << readsize << " readsize read serv";
    }
}
void* MainWindow::consume(void*){
    while(1){
        if(strlen((char*)buf_set)){
            int writesize = write(connectfd, buf_set, strlen(buf_set));
            qDebug() << strlen(buf_set) << " strlen write serv\n";
            qDebug() << writesize << " writesize write serv\n";
            *((char*)buf_set) = '\0';
        }
    }
}
void MainWindow::on_pushButton_clicked()
{
    strncpy((char*)buf_set, ui->textEdit->toPlainText().toStdString().c_str(), 256);
    ((char*)buf_set)[255] = '\0';
    qDebug() << strlen((char*)buf_set) << " input serv\n";
    ui->textEdit->setText("");
}
void MainWindow::updateText(const QString& text){
    ui->textBrowser->setText(text);
}
void MainWindow::timerEvent(QTimerEvent *event){
    if(event->timerId() == clock){
        QString str((char*)buf_get);
        ui->textBrowser->setText(str);
    }

}
