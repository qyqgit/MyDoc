#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDir>
#include <iostream>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    const QString& path = "/home/vi/Desktop";
    FindFile(path);
}
bool MainWindow::FindFile(const QString & path)
{
    int nFiles = 0;
    QDir dir(path);
     if (!dir.exists())
     return false;
     dir.setFilter(QDir::Dirs|QDir::Files);
     dir.setSorting(QDir::DirsFirst);
     QFileInfoList list = dir.entryInfoList();
     int i=0;
      do{

                       QFileInfo fileInfo = list.at(i);
                       if(fileInfo.fileName()=="."|fileInfo.fileName()=="..")
                       {
                               i++;
                               continue;
                       }
                       bool bisDir=fileInfo.isDir();
                       if(bisDir)
                       {
                           nFiles++;
                           std::cout << qPrintable(QString("%1 %2 %3").arg(fileInfo.size(), 10).arg(fileInfo.fileName(),10).arg(fileInfo.path()))<<std::endl;

                             FindFile(fileInfo.filePath());
                       }
                       else{
                           nFiles++;
                           std::cout << qPrintable(QString("%1 %2 %3").arg(fileInfo.size(), 10).arg(fileInfo.fileName(),10).arg(fileInfo.path()))<<std::endl;
                   }
                      i++;
            }while(i<list.size());
      return true;
}
