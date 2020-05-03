#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QBitmap>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    //QPixmap 图片背景透明
    p.drawPixmap(0,0,QPixmap("://11.png"));
    //QBitmap 图片背景透明
    p.drawPixmap(200,0,QBitmap("://11.png"));

    //QPixmap 图片背景白色
    QPixmap pixmap;
    pixmap.load("://11.png");
    p.drawPixmap(0,220,pixmap);

    //QBitmap 图片背景白色
    QBitmap bitmap;
    bitmap.load("://11.png");
    p.drawPixmap(200,220,bitmap);
}
