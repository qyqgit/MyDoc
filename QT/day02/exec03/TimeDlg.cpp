#include "TimeDlg.h"
#include <QVBoxLayout>
#include <QTime>
TimeDlg::TimeDlg(){
    labTime = new QLabel(this);
    labTime->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    btnTime = new QPushButton("time", this);
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(labTime);
    layout->addWidget(btnTime);
    connect(btnTime, SIGNAL(clicked()), this, SLOT(showTime()));

}
void TimeDlg::showTime(){
    labTime->setText(QTime::currentTime().toString("hh:mm:ss ap"));
}
