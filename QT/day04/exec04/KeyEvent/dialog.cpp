#include "dialog.h"
#include "ui_dialog.h"
#include <QDebug>
#include <QKeyEvent>
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}
void Dialog::keyPressEvent(QKeyEvent *event){
    qDebug() << "push:" << event->key();
    if(event->modifiers() & Qt::ShiftModifier)
        qDebug() << "shift";
    else if(event->modifiers() & Qt::ControlModifier)
        qDebug() << "ctrl";
    else if(event->modifiers() & Qt::AltModifier)
        qDebug() << "alt";
    QPoint pt = ui->label->pos();
    if(event->key() == Qt::Key_Up){
        ui->label->move(pt.x(), pt.y() - 1);
    }else if(event->key() == Qt::Key_Left){
        ui->label->move(pt.x() - 1, pt.y());
    }
}
void Dialog::keyReleaseEvent(QKeyEvent *event){
    qDebug() << "pop:" << event->key();
    if(event->modifiers() & Qt::ShiftModifier)
        qDebug() << "shift";
    else if(event->modifiers() & Qt::ControlModifier)
        qDebug() << "ctrl";
    else if(event->modifiers() & Qt::AltModifier)
        qDebug() << "alt";
}
