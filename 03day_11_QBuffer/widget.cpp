#include "widget.h"
#include "ui_widget.h"
#include <QBuffer>//内存文件
#include <QDebug>
#include <QDataStream>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QByteArray array;
    QBuffer memFile(&array);//创建内存文件
    memFile.open(QIODevice::WriteOnly);
    memFile.write("1111");
    memFile.write("2222");
    memFile.write("3333");
    memFile.close();
    qDebug() << memFile.buffer();//输出时，三个字符串会连在一起，"111122223333"
    qDebug() << "array" << array;

/*
 * 以下这种取的方式更常用
 */
    QBuffer memFile1;
    memFile1.open(QIODevice::WriteOnly);
    QDataStream stream(&memFile1);
    stream <<QString("测试")<<250;
    memFile1.close();
    qDebug() << memFile1.buffer();

    memFile1.open(QIODevice::ReadOnly);
    QDataStream in;
    in.setDevice(&memFile1);
    QString str;
    int a;
    in >>str >>a;
    memFile1.close();
    qDebug() <<str.toUtf8().data()<<a;



}

Widget::~Widget()
{
    delete ui;
}
