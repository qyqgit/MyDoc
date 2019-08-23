#include <QApplication>
#include <QDialog>
#include "ui_CalDlg.h"
using namespace Ui;
int main(int argc, char* argv[]){
    QApplication app(argc, argv);
    QDialog qdlg;
    CalDlg dlg;
    dlg.setupUi(&qdlg);
    qdlg.show();
    return app.exec();
}
