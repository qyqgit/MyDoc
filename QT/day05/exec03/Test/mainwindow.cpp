#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QRect>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mrc = new MyRect();
    clock = startTimer(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::paintEvent(QPaintEvent *){
    qDebug() << "paint";
    QPainter painter(this);
    mrc->showMrc(&painter);

}
void MainWindow::timerEvent(QTimerEvent *){
    this->update();
    mrc->moveMrc(0,0);
    mrc->resizeMrc(100,100);
    mrc->setTextMrc("sss");
}
