#include "myrect.h"
#include <QFrame>
#include <QPainter>
#include <QRect>
#include <QDebug>
MyRect::MyRect(QWidget *parent) :
    QFrame(parent)
{
    srand((int)this);
    rc = new QRect(rand()%100 + 1,rand()%100 + 1,rand()%100 + 1,rand()%100 + 1);
    color = new QColor(rand()%255 + 1,rand()%255 + 1,rand()%255 + 1,rand()%255 + 1);
    text = new QString("");
}

MyRect::~MyRect()
{
    delete rc;
    delete color;
    delete text;
}


void MyRect::timerEvent(QTimerEvent *event){
    qDebug() << "x";
}
void MyRect::showMrc(QPainter* painter){
    painter->fillRect(*this->rc, *this->color);
    painter->drawText(*this->rc, Qt::AlignCenter,*this->text,0);
    painter->drawRect(*this->rc);
}
void MyRect::moveMrc(QPoint *pt){
    this->rc->setRect(pt->x(),pt->y(),this->rc->width(),this->rc->height());
}
void MyRect::moveMrc(int x, int y){
    this->rc->setRect(x,y,this->rc->width(),this->rc->height());
}
void MyRect::resizeMrc(QRect *rc){
    this->rc->setRect(rc->x(),rc->y(),rc->width(),rc->height());
}
void MyRect::resizeMrc(int w, int h){
    this->rc->setRect(this->rc->x(),this->rc->y(),w,h);
}
void MyRect::setTextMrc(QString *text){
    this->text = text;
}
void MyRect::setTextMrc(const char *text){
    delete this->text;
    this->text = new QString(text);
}
