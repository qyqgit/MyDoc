#include "showpicdlg.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ShowPicDlg w;
    w.show();

    return a.exec();
}
