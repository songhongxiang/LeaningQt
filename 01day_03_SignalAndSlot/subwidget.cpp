#include "subwidget.h"

subWidget::subWidget(QWidget *parent) : QWidget(parent)
{
    this->setWindowTitle("子窗口");
    b.setParent(this);
    b.setText("切换到主窗口");
    b.move(100,100);
    resize(400,300);//设置窗口大小

    connect(&b,&QPushButton::clicked,this,&subWidget::sendSlot);
}

void subWidget::sendSlot()
{
    emit mySignal();
    emit mySignal(250,"我是子窗口");
}
