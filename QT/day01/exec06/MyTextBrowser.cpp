#include <QTextEdit>
#include "MyTextBrowser.h"

MyTextBrowser::MyTextBrowser(QTextEdit& textEdit){
    edit = &textEdit;
}
void MyTextBrowser::echoText(){
    setText(edit->toPlainText());
}

