#include <QTextEdit>
#include <QTextBrowser>

class MyTextBrowser: public QTextBrowser{
    Q_OBJECT
public:
    QTextEdit* edit;
    MyTextBrowser(QTextEdit& textEdit);
public slots:
    void echoText();
};
