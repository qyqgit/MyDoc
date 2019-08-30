#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

#include <stdio.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <pthread.h>

#define PORT_NUM 2233
#define IP_ADDR "127.0.0.1"

char buf_get[256];
char buf_set[256];
int socketfd;

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
    pthread_create(&mid, NULL, main_clix, NULL);
}
void* MainWindow::main_clix(void*){

    struct sockaddr_in serv;
    serv.sin_family = AF_INET;
    serv.sin_port = htons(PORT_NUM);
    inet_pton(AF_INET, IP_ADDR, &serv.sin_addr);
    socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if(socketfd == -1){
        perror("socket");
        return (void*)-1;
    }
    int status = ::connect(socketfd, (struct sockaddr*)&serv, sizeof(serv));
    if(status == -1){
        perror("connect");
        return (void*)-1;
    }

    pthread_t pid, cid;
    pthread_create(&pid, NULL, product, NULL);
    pthread_create(&cid, NULL, consume, NULL);

    pthread_join(pid, NULL);
    pthread_join(cid, NULL);
    ::close(socketfd);
    return (void*)0;
}
void* MainWindow::product(void*){
    while(1){
        if(strlen((char*)buf_set)){
            int writesize = write(socketfd, buf_set, strlen(buf_set));
            qDebug() << writesize << "write clix\n";
            *((char*)buf_set) = '\0';
        }
    }
}
void* MainWindow::consume(void*){
    while(1){
        int readsize = read(socketfd, buf_get, 256);
        ((char*)buf_get)[readsize] = '\0';
        qDebug() << strlen((char*)buf_get) << " " << readsize << "read clix\n";
    }
}
void MainWindow::on_pushButton_clicked()
{
    strncpy((char*)buf_set, ui->textEdit->toPlainText().toStdString().c_str(), 256);
    ((char*)buf_set)[255] = '\0';
    qDebug() << strlen((char*)buf_set) << " input clix\n";
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
