#include "TimeDlg.h"
#include <QApplication>
int main(int argc, char* argv[]){
    QApplication app(argc, argv);
    TimeDlg dlg;
    dlg.show();
    return app.exec();
}
