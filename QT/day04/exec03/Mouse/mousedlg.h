#ifndef MOUSEDLG_H
#define MOUSEDLG_H

#include <QMainWindow>
#include <QPoint>
#include <QMouseEvent>
namespace Ui {
class MouseDlg;
}

class MouseDlg : public QMainWindow
{
    Q_OBJECT

public:
    explicit MouseDlg(QWidget *parent = 0);
    ~MouseDlg();
public:
    bool m_press;
    QPoint m_pt;
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

private:
    Ui::MouseDlg *ui;
};

#endif // MOUSEDLG_H
