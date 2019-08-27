#ifndef SHOWPICS_H
#define SHOWPICS_H

#include <QDialog>

namespace Ui {
class ShowPics;
}

class ShowPics : public QDialog
{
    Q_OBJECT

public:
    explicit ShowPics(QWidget *parent = 0);
    ~ShowPics();
public:
    int m_index;
    void paintEvent(QPaintEvent*);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::ShowPics *ui;
};

#endif // SHOWPICS_H
