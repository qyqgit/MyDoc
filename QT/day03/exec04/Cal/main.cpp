#include "CalDig.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CalDig w;
    w.show();

    return a.exec();
}
