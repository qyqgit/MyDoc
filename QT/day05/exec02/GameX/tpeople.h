#ifndef TPEOPLE_H
#define TPEOPLE_H
#include <QTextBrowser>
class TPeople : public QTextBrowser
{
    Q_OBJECT

public:
    explicit TPeople(QWidget *parent = 0);
    ~TPeople();
public:
    void born();
    void eat(int life);
    void hit(int power);
    void die();
    int life;
    int clock;
private:
};
#endif // TPEOPLE_H

