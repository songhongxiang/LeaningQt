#include "mybutton.h"
#include <QMouseEvent>
#include <QDebug>

myButton::myButton(QWidget *parent) : QPushButton(parent)
{

}

void myButton::mousePressEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton)
    {
        //如果是左键按下
        qDebug()<<"按下的是左键";
    }
    else {
        //不作处理
        //QPushButton::mousePressEvent(e);
        //如果把语句放在这儿，而没有后面那句，
        //信号被忽略以后便不会继续往下传，因此clicked信号
        //就不会被触发，其所对应的槽函数当然也不会被执行
        //这种问题务必要注意，可以重写自己的事件，
        //但执行完后务必保证信号会继续往下传，否则会导致
        //后续信号无法继续接收，这种BUG很难找出来！！
    }
    //信号忽略，继续往下传
    QPushButton::mousePressEvent(e);
}
