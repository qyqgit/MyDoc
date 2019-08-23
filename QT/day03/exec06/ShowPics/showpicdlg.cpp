#include "showpicdlg.h"
#include "ui_showpicdlg.h"
#include <QPainter>
#include <QImage>
#include <QRect>

ShowPicDlg::ShowPicDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShowPicDlg)
{
    ui->setupUi(this);
}

ShowPicDlg::~ShowPicDlg()
{
    delete ui;
}
void ShowPicDlg::paintEvent(QPaintEvent*){
    QPainter painter(this);
    QRect rc = ui->frmPics->rect();
    QImage img(":/images/0.jpg");
    painter.drawImage(rc, img);
}
