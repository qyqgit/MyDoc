#include "dialog.h"
#include "ui_dialog.h"
#include <QDir>
#include <QTime>
#include <QPainter>
#include <QRect>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    loadPics("./photos");
    if(!m_vec.empty()){
        qsrand(QTime::currentTime().msec());
        m_index = qrand() % m_vec.size();
    }

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::loadPics(QString path){
    QDir dir(path);
    foreach(QString file, dir.entryList(QDir::Files)){
        QString name = file;
        name.resize(name.lastIndexOf("."));

        m_vec << qMakePair(name, QImage(path + "/" + file));
    }
    foreach(QString subdir, dir.entryList(QDir::Dirs | QDir::NoDotAndDotDot)){
        loadPics(path + "/" + subdir);
    }
}
void Dialog::paintEvent(QPaintEvent *){
    QPainter painter(this);
    QRect rc = ui->frame->rect();
    rc.translate(ui->frame->pos());
    painter.drawImage(rc, m_vec[m_index].second);
    ui->label->setText(m_vec[m_index].first);
}
void Dialog::timerEvent(QTimerEvent *event){
    if(event->timerId() == m_clockStart){
        m_index = qrand() % m_vec.size();
        this->update();

    }else if(event->timerId() == m_clockStop){
        killTimer(m_clockStart);
        killTimer(m_clockStop);
        ui->pushButton->setEnabled(true);
    }

}

void Dialog::on_pushButton_clicked()
{
    m_clockStart = startTimer(5);//50ms
    m_clockStop = startTimer(10000);//5s
    ui->pushButton->setEnabled(false);
}
