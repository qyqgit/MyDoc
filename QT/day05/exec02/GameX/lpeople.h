#ifndef LPEOPLE_H
#define LPEOPLE_H
#include <QLabel>
class LPeople : public QLabel
{
    Q_OBJECT

public:
    explicit LPeople(QWidget *parent = 0);
    ~LPeople();
public:
    void born();
    void eat(int life);
    void hit(int power);
    void die();
    int life;
    int clock;
private:
};
#endif // LPEOPLE_H

