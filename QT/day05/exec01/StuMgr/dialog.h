#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QMessageBox>
#include <QDebug>
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
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

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
