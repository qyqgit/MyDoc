#include <QApplication>
#include <QPushButton>
#include <QTextCodec>
int main(int argc, char* argv[]){
    QApplication app(argc, argv);
    QTextCodec* codec = QTextCodec::codecForName("gbk");
    QPushButton pushButton(codec->toUnicode("°´Å¥"));
    pushButton.show();
    return app.exec();
}
