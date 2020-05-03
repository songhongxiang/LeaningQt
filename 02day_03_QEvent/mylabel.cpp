#include "mylabel.h"
#include <QMouseEvent>
#include <QDebug>

myLabel::myLabel(QWidget *parent) : QLabel(parent)
{
    //要想一进界面就有效
    this->setMouseTracking(true);
}

void myLabel::mousePressEvent(QMouseEvent *ev)
{
    int i = ev->x();
    int j = ev->y();
    //sprinf
    /*
     * QString str = QString("abc %1 ^_^ %2").arg(123).arg("mike");
     * str = abc 123 ^_^ mike
     */

    if(ev->button() == Qt::LeftButton)
    {
        qDebug() << "鼠标左键被按下！";
    }else if(ev->button() == Qt::RightButton)
    {
        qDebug() << "鼠标右键被按下！";
    }else if(ev->button() == Qt::MidButton)
    {
        qDebug() << "鼠标中键被按下！";
    }




    // 可嵌入html语句
    QString text = QString("<h1>Mouse Press:(%1,%2)</h1>")
            .arg(i).arg(j);
    this->setText(text);

}

void myLabel::mouseReleaseEvent(QMouseEvent *ev)
{

    QString text = QString("<h1>Mouse Release:(%1,%2)</h1>")
            .arg(ev->x()).arg(ev->y());
    this->setText(text);
}

void myLabel::mouseMoveEvent(QMouseEvent *ev)
{
    QString text = QString("<h1>Mouse Move:(%1,%2)</h1>")
            .arg(ev->x()).arg(ev->y());
    //this->setText(text);
}

void myLabel::enterEvent(QEvent *e)
{
    QString text = QString("<center><h1>Mouse enter</h1></center>");
    this->setText(text);
}

void myLabel::leaveEvent(QEvent *e)
{
    QString text = QString("<center><h1>Mouse leave</h1></center>");
    this->setText(text);
}
