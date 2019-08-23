#include <QMessageBox>
#include <QDebug>
#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_clicked()
{
    if(ui->lineEdit->text() == "root" && ui->lineEdit_2->text() == "123"){
        qDebug() << "success.";
        this->close();
    }else{
        QMessageBox msg(QMessageBox::Critical, "error", "login fail.", QMessageBox::Ok);
        msg.exec();
    }
}

void Login::on_pushButton_2_clicked()
{
    QMessageBox msg(QMessageBox::Question, "Cancel", "cancel?", QMessageBox::Yes | QMessageBox::No);
    if(msg.exec() == QMessageBox::Yes){
        this->close();
    }
}
