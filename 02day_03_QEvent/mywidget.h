#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>

namespace Ui {
class myWidget;
}

class myWidget : public QWidget
{
    Q_OBJECT

public:
    explicit myWidget(QWidget *parent = nullptr);
    ~myWidget();
protected:
    //键盘按下事件
    void keyPressEvent(QKeyEvent *);
    //定时器事件
    void timerEvent(QTimerEvent *);
    //关闭事件
    void closeEvent(QCloseEvent *);

    //重写event事件
    bool event(QEvent *);

    //事件过滤器
    bool eventFilter(QObject *,QEvent *);

private:
    Ui::myWidget *ui;

    int timerID;
    int timerID2;
};

#endif // MYWIDGET_H
