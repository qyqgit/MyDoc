#ifndef __CALDLG_H
#define __CALDLG_H
#include <QDialog>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
class CalDlg : public QDialog{
    Q_OBJECT//启动moc元对象编译器
public:
    CalDlg();
private slots://qt拓展语法
    void enableCal();
    void calResult();

private:
    QLineEdit* m_editX;
    QLabel* m_labSig;
    QLineEdit* m_editY;
    QPushButton* m_btnCal;
    QLineEdit* m_editZ;

};
#endif
