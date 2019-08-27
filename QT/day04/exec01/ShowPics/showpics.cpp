#include "showpics.h"
#include "ui_showpics.h"
#include <QPainter>
#include <QImage>
#include <QRect>

ShowPics::ShowPics(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShowPics)
{
    ui->setupUi(this);
    m_index = 0;
}

ShowPics::~ShowPics()
{
    delete ui;
}
void ShowPics::paintEvent(QPaintEvent *){
    QPainter painter(this);
    QRect rc = ui->frame->rect();//size of frame
    rc.translate(ui->frame->pos());
    QImage img(":/images/" + QString::number(m_index) + ".jpg");
    painter.drawImage(rc, img);//size of dialog

}
void ShowPics::on_pushButton_clicked()
{
    if(--m_index == -1)
        m_index = 7;
    this->update();

}

void ShowPics::on_pushButton_2_clicked()
{
    if(++m_index == 8)
        m_index = 0;
    this->update();
}

void ShowPics::on_pushButton_3_clicked()
{
    this->close();
}
