#include <QDialog>
#include "ui_Time.h"
using namespace Ui;
class MyTime: public QDialog{//has a
    Q_OBJECT
public:
    MyTime();
    Time* pTime;
public slots:
    void showTime();
};
