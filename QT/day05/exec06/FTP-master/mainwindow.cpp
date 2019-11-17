#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_ftp.setHostPort("127.0.0.1", 21);
    m_ftp.setUserInfo("ftpuser_test", "12345");

    connect(ui->Btn_upload, SIGNAL(clicked(bool)), this, SLOT(upload()));
    connect(ui->Btn_download, SIGNAL(clicked(bool)), this, SLOT(download()));

}

MainWindow::~MainWindow()
{
    delete ui;
}
// 上传文件
void MainWindow::upload()
{
    m_ftp.put("/home/vi/Desktop/a.out", "ftp/b.out");
    connect(&m_ftp, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(error(QNetworkReply::NetworkError)));
    connect(&m_ftp, SIGNAL(uploadProgress(qint64, qint64)), this, SLOT(uploadProgress(qint64, qint64)));
}

// 下载文件
void MainWindow::download()
{
    m_ftp.get("/home/wang/Qt.zip", "F:\\Qt.zip");
    connect(&m_ftp, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(error(QNetworkReply::NetworkError)));
    connect(&m_ftp, SIGNAL(downloadProgress(qint64, qint64)), this, SLOT(downloadProgress(qint64, qint64)));
}

// 更新上传进度
void MainWindow::uploadProgress(qint64 bytesSent, qint64 bytesTotal)
{
    ui->progressBar_upload->setMaximum(bytesTotal);
    ui->progressBar_upload->setValue(bytesSent);
}

// 更新下载进度
void MainWindow::downloadProgress(qint64 bytesReceived, qint64 bytesTotal)
{
    ui->progressBar_download->setMaximum(bytesTotal);
    ui->progressBar_download->setValue(bytesReceived);
}

// 错误处理
void MainWindow::error(QNetworkReply::NetworkError error)
{
    switch (error) {
    case QNetworkReply::HostNotFoundError :
        qDebug() << QString::fromLocal8Bit("主机没有找到");
        break;
        // 其他错误处理
    default:
        break;
    }
}

