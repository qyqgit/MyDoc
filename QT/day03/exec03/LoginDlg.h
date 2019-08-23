#ifndef __LOGINDLG_H
#define __LOGINDLG_H
#include <QDialog>
#include "ui_Login.h"
class LoginDlg:public QDialog, public Ui::LoginDlg{
    Q_OBJECT
    public:
        LoginDlg();
    private slots:
        void sureLogin();
        void cancelLogin();
    private:
};
#endif
