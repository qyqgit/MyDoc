#ifndef __TIMEDLG_H
#define __TIMEDLG_H
#include <QLabel>
#include <QDialog>
#include <QPushButton>
class TimeDlg : public QDialog{
    Q_OBJECT
public:
    TimeDlg();
private slots:
    void showTime();
    
private:
    QLabel* labTime;
    QPushButton* btnTime;
};
#endif
