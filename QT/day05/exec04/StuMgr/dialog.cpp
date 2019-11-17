#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    createDB();
    createTB();
    queryData();
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::createDB(){
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("exec01.db");

    if(!db.open()){
        QMessageBox msg(QMessageBox::Critical, "ERROR", db.lastError().text(), QMessageBox::Ok);
        msg.exec();
    }
}
void Dialog::createTB(){
    QString str = QString("create table student(id int primary key not null,name text not null,score real not null)");
    QSqlQuery query;
    query.exec(str);
}
void Dialog::queryData(){

    QSqlQuery query;
    int i = 0, j = 0, nColumn, nRow;
    query.prepare("select * from student");
    query.exec();
    query.last();
    QSqlRecord record = query.record();
    nRow = query.at() + 1;
    nColumn = record.count() + 1;
    ui->tableWidget->setRowCount(nRow);
    ui->tableWidget->setColumnCount(nColumn);
    query.first();
    while(j<nRow)
    {
        for (i = 0; i<nColumn; i++){
            if(i == nColumn - 1){
                QPushButton *btn = new QPushButton(this);
                btn->setText("update");
                IDS *dat = new IDS();
                dat->id = query.value(0).toString();
                btn->setUserData(0, dat);
                ui->tableWidget->setCellWidget(j, i, btn);
                connect(btn, SIGNAL(clicked(bool)), this, SLOT(push1()));
            }
            ui->tableWidget->setItem(j, i, new QTableWidgetItem(query.value(i).toString()));
        }
        j++;
        query.next();
    }
}

void Dialog::push1(){
    QPushButton *senderObj=qobject_cast<QPushButton*>(sender());
    IDS *dat = dynamic_cast<IDS*>(senderObj->userData(0));
    qDebug() << dat->id;
}
void Dialog::on_pushButton_Order_clicked()
{
    QString cond;
    QString value = ui->comboBox_ID->currentText();
    if(ui->comboBox_ASC->currentIndex() == 1){
        cond = "DESC";
    } else {
      cond = "ASC";
    }
    QString str = QString("select * from student order by %1 %2").arg(value).arg(cond);
    model.setQuery(str);
    //ui->tableView->setModel(&model);
}

void Dialog::on_pushButton_Add_clicked()
{
    int id = ui->lineEdit_ID->text().toInt();
    QString name = ui->lineEdit_Name->text();
    double score = ui->lineEdit_Score->text().toDouble();

    QString str = QString("insert into student values(%1, '%2', %3)").arg(id).arg(name).arg(score);
    QSqlQuery query;
    query.exec(str);
    queryData();
}

void Dialog::on_pushButton_Remove_clicked()
{
    int id = ui->lineEdit_ID->text().toInt();
    QString str = QString("delete from student where id = %1").arg(id);
    QSqlQuery query;
    query.exec(str);
    queryData();
}

void Dialog::on_pushButton_Edit_clicked()
{
    int id = ui->lineEdit_ID->text().toInt();
    double score = ui->lineEdit_Score->text().toDouble();
    QString str = QString("update student set score = '%1' where id = %2").arg(score).arg(id);
    QSqlQuery query;
    query.exec(str);
    queryData();
}

