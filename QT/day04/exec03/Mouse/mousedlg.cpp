#include "mousedlg.h"
#include "ui_mousedlg.h"
#include <QPoint>
MouseDlg::MouseDlg(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MouseDlg)
{
    ui->setupUi(this);
    m_press = false;
}

MouseDlg::~MouseDlg()
{
    delete ui;
}
void MouseDlg::mousePressEvent(QMouseEvent *event){
    if(event->button() == Qt::LeftButton){
        QRect rc = ui->label->rect();
        rc.translate(ui->label->pos());
        if(rc.contains(event->pos())){
            m_press = true;
            m_pt = ui->label->pos() - event->pos();
        }

    }
}
void MouseDlg::mouseMoveEvent(QMouseEvent *event){
    if(m_press == true){
        QPoint pt = event->pos() + m_pt;
        if(pt.x() < 0)
            pt.setX(0);
        if(pt.x() > this->width() - ui->label->width())
            pt.setX(this->width() - ui->label->width());
        if(pt.y() < 0)
            pt.setY(0);
        if(pt.y() > this->height() - ui->label->height())
            pt.setY(this->height() - ui->label->height());
        //ui->label->move(event->pos() + m_pt);
        ui->label->move(pt);
    }
}
void MouseDlg::mouseReleaseEvent(QMouseEvent *event){
    m_press = false;
}
