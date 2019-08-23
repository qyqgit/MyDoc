#include <QTime>
#include "Time.h"
MyTime::MyTime(){
    pTime = new Time();
    pTime->setupUi(this);
    connect(pTime->myButton, SIGNAL(clicked()), this, SLOT(showTime()));
}
void MyTime::showTime(){
    pTime->myLabel->setText(QTime::currentTime().toString("hh:mm:ss  AP"));
}
