#include "tpeople.h"
#include <QTimer>
#include <QtMath>
#include <QTextBrowser>
TPeople::TPeople(QWidget *parent) :
    QTextBrowser(parent)
{
    this->born();
}

TPeople::~TPeople()
{
}
void TPeople::born(){
    qsrand((int)this);
    this->life = (qrand() % 100) + 1;
    this->clock = startTimer(life/2 + 10);
}
void TPeople::eat(int life){
    int weight = this->life * this->life + life * life;
    this->life = qSqrt(weight);
    this->setText(QString().setNum(this->life));
    this->resize(this->life, this->life);
    killTimer(this->clock);
    this->clock = startTimer(this->life/2 + 5);
}
void TPeople::hit(int power){

}
void TPeople::die(){
    this->life = 0;
    //this->close();
    this->killTimer(this->clock);
}

