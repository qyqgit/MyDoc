#ifndef MYRECT
#define MYRECT

#include <QFrame>
#include <QRect>
#include <QPainter>
class MyRect : public QFrame
{
    Q_OBJECT

public:
    explicit MyRect(QWidget *parent = 0);
    ~MyRect();
public:
    void timerEvent(QTimerEvent* event);
    void showMrc(QPainter* painter);
    void moveMrc(QPoint* pt);
    void moveMrc(int x,int y);
    void resizeMrc(QRect* rc);
    void resizeMrc(int w,int h);
    void setTextMrc(QString* text);
    void setTextMrc(const char* text);
    QRect* rc;
    QString* text;
    QColor* color;
private:
};
#endif // MYRECT

