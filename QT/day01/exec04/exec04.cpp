#include <QApplication>
#include <QSlider>
#include <QSpinBox>
int main(int argc, char* argv[]){
    QApplication app(argc, argv);

    QSlider slider(Qt::Horizontal);
    //QSlider slider();
    slider.setRange(-20, 30);
    slider.setValue(0);
    slider.show();

    QSpinBox spin;
    spin.setRange(-30, 20);
    spin.setValue(0);
    spin.show();

    QObject::connect(&slider, SIGNAL(valueChanged(int)), &spin, SLOT(setValue(int)));
    QObject::connect(&spin, SIGNAL(valueChanged(int)), &slider, SLOT(setValue(int)));
    return app.exec();
}
