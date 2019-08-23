#include <QApplication>
#include <QTextBrowser>
#include <QTextEdit>
#include <QPushButton>
#include "MyTextBrowser.h"
using namespace std;

int main(int argc, char* argv[]){
    QApplication app(argc, argv);

    QTextEdit textEdit;
    textEdit.move(50, 50);
    textEdit.show();

    MyTextBrowser textBrowser(textEdit);
    textBrowser.move(0, 0);
    textBrowser.show();

    QPushButton button("submit");
    button.move(200, 200);
    button.show();

    
    QObject::connect(&button, SIGNAL(clicked()), &textBrowser, SLOT(echoText()));
    return app.exec();
}
