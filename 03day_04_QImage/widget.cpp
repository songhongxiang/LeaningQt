#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QRgb>
#include <QImage>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //创建一个绘图设备，背景透明
    QImage image(400,300,QImage::Format_ARGB32);
    QPainter p;
    p.begin(&image);

    //绘图
    p.drawImage(0,0,QImage("../11.png"));//项目上一层路径下

    //对绘图设备前50个像素点进行操作，一般不会这么用
    for(int i= 0;i < 50; i++)
    {
        for(int j=0;j<50;j++)
        {
            image.setPixel(QPoint(i,j), qRgb(0,255,0));
        }
    }


    //注意，保存的时候是绘图设备保存
    image.save("image.png");//注意，该路径是在项目build文件下
    p.end();
}

Widget::~Widget()
{
    delete ui;
}
