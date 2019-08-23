#include "CalDig.h"
#include "ui_CalDig.h"

CalDig::CalDig(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CalDig)
{
    ui->setupUi(this);
    connect(ui->lineEdit, SIGNAL(textChanged(QString)), this, SLOT(enableCal()));
    connect(ui->lineEdit_2, SIGNAL(textChanged(QString)), this, SLOT(enableCal()));
}

CalDig::~CalDig()
{
    delete ui;
}

void CalDig::on_m_btnCal_clicked()
{
    double res = ui->lineEdit->text().toDouble() + ui->lineEdit_2->text().toDouble();
    ui->lineEdit_3->setText(QString::number(res, 'g', 6));

}
void CalDig::enableCal(){
    bool bXok, bYok;
    ui->lineEdit->text().toDouble(&bXok);
    ui->lineEdit_2->text().toDouble(&bYok);
    ui->m_btnCal->setEnabled(bXok && bYok);

}
