#include <QApplication>
#include <QPushButton>
#include <QLabel>
#include <QDialog>
#include <QWidget>
int main(int argc, char* argv[]){
    QApplication app(argc, argv);
    //QDialog dlg;
    QWidget dlg;
    dlg.move(100, 100);
    QLabel label("hello world.",&dlg);
    label.move(20, 20);
    //label.show();

    QPushButton button("close label",&dlg);
    button.move(50, 50);
    //button.show();
    QObject::connect(&button, SIGNAL(clicked()), &label, SLOT(close()));
    QObject::connect(&button, SIGNAL(clicked()), &button, SLOT(close()));
    dlg.show();
    return app.exec();
}
