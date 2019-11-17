#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QMessageBox>
#include <QDebug>
#include <QSqlRecord>
#include <QPushButton>
#include <QObjectUserData>

namespace Ui {
class Dialog;
}
struct IDS:QObjectUserData{
    QString id;
};
class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = NULL);
    ~Dialog();
public:
    QSqlDatabase db;
    QSqlQueryModel model;
    void createDB();
    void createTB();
    void queryData();
private slots:
    void on_pushButton_Order_clicked();

    void on_pushButton_Add_clicked();

    void on_pushButton_Remove_clicked();

    void on_pushButton_Edit_clicked();
    void push1();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
