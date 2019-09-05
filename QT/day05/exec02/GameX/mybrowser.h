#ifndef MYBROWSER
#define MYBROWSER
#include <QTextBrowser>
#include "tpeople.h"
class MyBrowser:public TPeople{
    Q_OBJECT
public:
    explicit MyBrowser(QWidget *parent = 0);
    ~MyBrowser();
public:
    void timerEvent(QTimerEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    bool goup;
    bool godown;
    bool goleft;
    bool goright;
private:
};
#endif // MYBROWSER

