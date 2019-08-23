#ifndef __CLOCK_H
#define __CLOCK_H
#include <QDialog>
#include <QString>
#include <QLabel>
#include <QPushButton>
class Clock : public QDialog{
    Q_OBJECT//启动moc元对象编译器
public:
    Clock();
private slots:
    void showTime();
private:
    QLabel* pLabel;
    QPushButton* pButton;
    QString* pTime;
};
#endif
