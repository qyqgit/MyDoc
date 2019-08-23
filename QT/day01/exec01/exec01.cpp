#include <QApplication>
#include <QLabel>
int main(int argc, char* argv[]){
    //定义应用程序类 对象
    QApplication app(argc, argv);
    QLabel label("hello world.");
    //显示标签组件
    label.show();
    return app.exec();//进入信号(事件)循环
}
