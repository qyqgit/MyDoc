#include "lpeople.h"
#include <QTimer>
#include <QtMath>
#include <QLabel>
LPeople::LPeople(QWidget *parent) :
    QLabel(parent)
{
    this->born();
}

LPeople::~LPeople()
{
}
void LPeople::born(){
    qsrand((int)this);
    this->life = (qrand() % 100) + 1;
    this->clock = startTimer(life/2 + 10);
}
void LPeople::eat(int life){
    int weight = this->life * this->life + life * life;
    this->life = qSqrt(weight);
    this->setText(QString().setNum(this->life));
    this->resize(this->life, this->life);
    killTimer(this->clock);
    this->clock = startTimer(this->life/2 + 5);
}
void LPeople::hit(int power){

}
void LPeople::die(){
    this->life = 0;
    //this->close();
    this->killTimer(this->clock);
}
