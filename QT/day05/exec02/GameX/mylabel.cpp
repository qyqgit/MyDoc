#include "mylabel.h"
#include <QTimer>
#include "lpeople.h"
#include <QPoint>
#include <QDebug>
#include <QtMath>
MyLabel::MyLabel(QWidget *parent) :
    LPeople(parent)
{
    qsrand((int)this);
    pt = new QPoint();
    pt->rx() = qrand() % this->parentWidget()->width();
    pt->ry() = qrand() % this->parentWidget()->height();
    this->move(pt->x(), pt->y());
    k = (qrand() % 1) + 1;
    b = 0;
    turn = (qrand() % 2);
    this->setText(QString().setNum(life));
    this->resize(life,life);
    this->setStyleSheet("border:2px solid red");
    this->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    this->getkb(&this->k, &this->b, this->pt);
}

MyLabel::~MyLabel()
{
    delete pt;
}
void MyLabel::timerEvent(QTimerEvent *){
    this->goStraightLine(this->pt, &this->k, &this->b, &this->turn);
    this->move(*pt);
}
void MyLabel::getkb(float *k, int *b, QPoint *pt){
    *k = 0 - *k;
    *b = pt->y() - *k * pt->x();
}
void MyLabel::goStraightLine(QPoint *pt, float *k, int *b, bool *turn){
    if(pt->x() >= this->parentWidget()->width()){
        *turn ^= 1;
        getkb(k, b, pt);
    }
    if(pt->x() <= 0){
        *turn ^= 1;
        getkb(k, b, pt);
    }
    if(pt->y() >= this->parentWidget()->height()){
        getkb(k, b, pt);
    }
    if(pt->y() <= 0){
        getkb(k, b, pt);
    }
    if(*turn)
        pt->rx()++;
    else
        pt->rx()--;
    pt->ry() = *k * pt->x() + *b;
}

