#ifndef __CALDLG_H
#define __CALDLG_H
#include <QDialog>
#include "ui_CalDlg.h"
class CalDlg : public QDialog, public Ui::CalDlg{//is a
    Q_OBJECT//启动moc元对象编译器
public:
    CalDlg();
private slots://qt拓展语法
    void enableCal();
    void calResult();
};
#endif
