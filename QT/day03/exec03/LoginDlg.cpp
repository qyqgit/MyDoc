#include "LoginDlg.h"
#include <QMessageBox>
#include <QDebug>
LoginDlg::LoginDlg(){
    setupUi(this);
    connect(m_ok, SIGNAL(clicked()), this, SLOT(sureLogin()));
    connect(m_cancel, SIGNAL(clicked()), this, SLOT(cancelLogin()));
}
void LoginDlg::sureLogin(){
    if(m_username->text() == "tarena" && m_pwd->text() == "123" ){
        qDebug() << "success.";
        close();
    }else{
        QMessageBox msg(QMessageBox::Critical, "error", "name or password error.", QMessageBox::Ok);
        msg.exec();
    }
}
void LoginDlg::cancelLogin(){
    QMessageBox msg(QMessageBox::Question, "Loign", "cancel?", QMessageBox::Yes | QMessageBox::No, this);
    if(msg.exec() == QMessageBox::Yes){
        //exit(0);
        this->close();
    }
}
