#include "widget.h"
#include "ui_widget.h"
#include <QPainter>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //绘图设备，400*300
    QPixmap pixmap(400,300);

    QPainter p(&pixmap);

    //填充背景为白色
    //法1：通过画家填充
    //p.fillRect(0,0,400,300,QBrush(Qt::white));
    //法2：通过绘图设备填充
    pixmap.fill(Qt::white);

    p.drawPixmap(0,0,80,80,QPixmap(":/new/prefix1/11.png"));

    //保存图片
    pixmap.save("../pixmap.png");
}

Widget::~Widget()
{
    delete ui;
}
