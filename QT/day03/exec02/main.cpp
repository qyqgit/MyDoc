#include <QApplication>
#include "Time.h"
int main(int argc, char* argv[]){
    QApplication app(argc, argv);
    MyTime time;
    time.show();
    return app.exec();
}
