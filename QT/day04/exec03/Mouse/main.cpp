#include "mousedlg.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MouseDlg w;
    w.show();

    return a.exec();
}
