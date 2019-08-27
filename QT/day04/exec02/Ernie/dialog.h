#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QPair>
#include <QVector>

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
    int m_index;
    int m_clockStart;//50ms
    int m_clockStop;//5s
    QVector< QPair<QString, QImage> > m_vec;
    void loadPics(QString path);
    void paintEvent(QPaintEvent *);
    void timerEvent(QTimerEvent *event);

private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
