#include "mywidget.h"
#include <QPushButton>
#include "mybutton.h"

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
{
    /* 对于父窗口，坐标系相对于屏幕
     * 原点：相对于屏幕左上角
     * x:往右递增
     * y:往下递增
     */
    move(750,300);

    QPushButton *b1 = new QPushButton(this);
    b1->setText("^_^");

    /* 对于子窗口，坐标系相对于父窗口
     * 原点：相对于父窗口左上角
     * x:往右递增
     * y:往下递增
     */
    b1->move(0,0);
    b1->resize(200,200);//设置按钮大小

    QPushButton *b2 = new QPushButton(b1);
    /* 对于子控件，坐标系相对于父控件
     * 原点：相对于父控件左上角
     * x:往右递增
     * y:往下递增
     */
    b2->move(50,50);
    b2->setText("@_@");

    myButton *b3 = new myButton(this);
    b3->setText("析构测试按钮");


}

MyWidget::~MyWidget()
{

}
