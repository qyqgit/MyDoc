#ifndef CALDIG_H
#define CALDIG_H

#include <QDialog>

namespace Ui {
class CalDig;
}

class CalDig : public QDialog
{
    Q_OBJECT

public:
    explicit CalDig(QWidget *parent = 0);
    ~CalDig();

private slots:
    void on_m_btnCal_clicked();
    void enableCal();

private:
    Ui::CalDig *ui;
};

#endif // CALDIG_H
