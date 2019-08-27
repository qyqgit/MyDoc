#include "showpics.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ShowPics w;
    w.show();

    return a.exec();
}
