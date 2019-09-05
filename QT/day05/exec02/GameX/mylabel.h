#ifndef MYLABEL_H
#define MYLABEL_H
#include <QLabel>
#include "lpeople.h"
class MyLabel:public LPeople{
    Q_OBJECT
public:
    explicit MyLabel(QWidget *parent = 0);
    ~MyLabel();
public:
    void timerEvent(QTimerEvent *event);
    void goStraightLine(QPoint* pt, float* k,int* b, bool* turn);
    QPoint* pt;
private:
    void getkb(float* k, int* b, QPoint *pt);
    float k;
    int b;
    bool turn;
};
#endif // MYLABEL_H

