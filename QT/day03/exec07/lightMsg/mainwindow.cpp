#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent, void* buf) :
    QMainWindow(parent),
    buf(buf),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    clock = startTimer(5);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    //ui->textBrowser->setText(ui->textEdit->toPlainText());
}
void MainWindow::updateText(const QString& text){
    ui->textBrowser->setText(text);
}
void MainWindow::timerEvent(QTimerEvent *event){
    if(event->timerId() == clock){
        QString str((char*)buf);
        ui->textBrowser->setText(str);
    }

}
