#include <QApplication>
#include "LoginDlg.h"
int main(int argc, char* argv[]){
    QApplication app(argc, argv);
    LoginDlg dlg;
    dlg.show();
    return app.exec();
}
