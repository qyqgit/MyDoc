#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mylabel.h"
#include "mybrowser.h"
#define NUM 15
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
    void timerEvent(QTimerEvent *event);
    MyLabel* labelx[NUM];
    MyBrowser* browser;
    int clock;
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
