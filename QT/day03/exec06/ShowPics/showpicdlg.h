#ifndef SHOWPICDLG_H
#define SHOWPICDLG_H

#include <QDialog>

namespace Ui {
class ShowPicDlg;
}

class ShowPicDlg : public QDialog
{
    Q_OBJECT

public:
    explicit ShowPicDlg(QWidget *parent = 0);
    ~ShowPicDlg();
    virtual void paintEvent(QPaintEvent*);

private:
    Ui::ShowPicDlg *ui;
};

#endif // SHOWPICDLG_H
