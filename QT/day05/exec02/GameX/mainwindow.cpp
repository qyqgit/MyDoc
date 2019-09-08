#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QRect>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    browser = new MyBrowser(this);
    for(int i = 0; i < NUM; i++){
        labelx[i] = new MyLabel(this);
    }
    clock = startTimer(20);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete browser;
    for(int i = 0; i < NUM; i++){
        delete labelx[i];
    }
}
void MainWindow::timerEvent(QTimerEvent *){
    QRect bRc = browser->rect();
    bRc.translate(browser->pos());
    for(int i = 0; i < NUM; i++){
        QRect lRc = labelx[i]->rect();
        lRc.translate(labelx[i]->pos());
        if(labelx[i]->life != 0 && browser->life!= 0 && bRc.contains(lRc)){
            browser->eat(labelx[i]->life);
            labelx[i]->die();
        }else if(labelx[i]->life != 0 && browser->life != 0 && lRc.contains(bRc)){
            labelx[i]->eat(browser->life);
            browser->die();
        }
    }
//    for(int i = 0; i < NUM; i++){
//        QRect lRci = labelx[i]->rect();
//        lRci.translate(labelx[i]->pos());
//        for(int j = 0; j < NUM; j++){
//            QRect lRcj = labelx[j]->rect();
//            lRcj.translate(labelx[j]->pos());
//            if(i != j && labelx[i]->life != 0 && labelx[j]->life != 0 && lRci.contains(lRcj)){
//                labelx[i]->eat(labelx[j]->life);
//                labelx[j]->die();
//            }
//        }
//    }
}
