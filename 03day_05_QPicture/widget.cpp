#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QPicture>



Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QPicture picture;
    QPainter p;
    p.begin(&picture);

    p.drawPixmap(0,0,80,80,QPixmap("../11.png"));
    p.drawLine(50,50,150,50);

    p.end();

    //注意：保存的是二进制文件
    picture.save("picture.png");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *)
{
    QPicture pic;
    pic.load("picture.png");//加载二进制文件

    QPainter p(this);
    p.drawPicture(0,0,pic);
}

