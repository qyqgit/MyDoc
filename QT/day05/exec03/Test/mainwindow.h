#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "myrect.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public:
    void paintEvent(QPaintEvent *);
    void timerEvent(QTimerEvent *);
    MyRect* mrc;
    int clock;
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
