#include "CalDlg.h"
#include <QApplication>
int main(int argc, char* argv[]){
    QApplication app(argc, argv);
    CalDlg dlg;
    dlg.show();
    return app.exec();

}
