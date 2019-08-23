#include <QApplication>
#include <QSlider>
#include <QSpinBox>
#include <QDialog>
int main(int argc, char* argv[]){
    QApplication app(argc, argv);
    
    QDialog dlg;
    QSlider slider(Qt::Horizontal, &dlg);
    //QSlider slider();
    slider.setRange(-20, 30);
    slider.setValue(0);
    slider.move(0, 50);
    //slider.show();

    QSpinBox spin(&dlg);
    spin.setRange(-30, 20);
    spin.setValue(0);
    //spin.show();

    QObject::connect(&slider, SIGNAL(valueChanged(int)), &spin, SLOT(setValue(int)));
    QObject::connect(&spin, SIGNAL(valueChanged(int)), &slider, SLOT(setValue(int)));
    dlg.show();
    return app.exec();
}
