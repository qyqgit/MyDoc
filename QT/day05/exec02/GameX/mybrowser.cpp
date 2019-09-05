
#include "mybrowser.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QKeyEvent>
#include <QTextBrowser>
#include <QString>
#include <QtMath>
MyBrowser::MyBrowser(QWidget *parent) :
    TPeople(parent)
{
    life = 50;
    this->setStyleSheet("border:1px solid black");
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setAlignment(Qt::AlignCenter);
    this->setText(QString().setNum(life));
    this->resize(life,life);
    this->move(this->parentWidget()->width()/2,this->parentWidget()->height()/2);
    goup = false;
    godown = false;
    goleft = false;
    goright = false;
}

MyBrowser::~MyBrowser()
{
}
void MyBrowser::timerEvent(QTimerEvent *event){
    if(goup){
        this->move(this->pos().x(), this->pos().y() - 1);
    }
    if(goleft){
        this->move(this->pos().x() - 1, this->pos().y());
    }
    if(godown){
        this->move(this->pos().x(), this->pos().y() + 1);
    }
    if(goright){
        this->move(this->pos().x() + 1, this->pos().y());
    }
}
void MyBrowser::keyPressEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_Up)
        goup = true;
    if(event->key() == Qt::Key_Left)
        goleft = true;

    if(event->key() == Qt::Key_Down)
        godown = true;

    if(event->key() == Qt::Key_Right)
        goright = true;
}
void MyBrowser::keyReleaseEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_Up)
        goup = false;

    if(event->key() == Qt::Key_Left)
        goleft = false;

    if(event->key() == Qt::Key_Down)
        godown = false;

    if(event->key() == Qt::Key_Right)
        goright = false;
}
