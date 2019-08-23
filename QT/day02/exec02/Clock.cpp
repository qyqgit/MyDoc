#include <QTime>
#include <QString>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include "Clock.h"
Clock::Clock(){
    pTime = new QString(QTime::currentTime().toString());
    pLabel = new QLabel("00:00:00", this);
    pButton = new QPushButton("click", this);
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(pLabel);
    layout->addWidget(pButton);
    connect(pButton, SIGNAL(clicked()), this, SLOT(showTime()));

}
void Clock::showTime(){
    pLabel->setText(QTime::currentTime().toString());
}
