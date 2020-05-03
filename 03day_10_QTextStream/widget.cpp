#include "widget.h"
#include "ui_widget.h"
#include <QTextStream>
#include <QFile>
#include <QDebug>
#define cout qDebug() << "[" << __FILE__ <<"："<<__LINE__ <<"]"


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    writeData();
    readData();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::writeData()
{
    QFile file;
    file.setFileName("../demo.txt");

    bool isOk = file.open(QIODevice::WriteOnly);
    if(true == isOk)
    {
        QTextStream stream(&file);
        //指定编码
        stream.setCodec("UTF-8");

        stream <<QString("主要看气质")<<250;
        file.close();
    }
}

void Widget::readData()
{
    QFile file;
    file.setFileName("../demo.txt");

    bool isOk = file.open(QIODevice::ReadOnly);
    if(true == isOk)
    {
        QTextStream stream(&file);
        //指定编码
        stream.setCodec("UTF-8");
        QString str;
        int a;
//        stream >> str >> a;
//        cout << str.toUtf8().data() << a;
        /*
         * 以上这种方式，调试结果如下：
         * [ ..\03day_10_QTextStream\widget.cpp ： 54 ] 主要看气质250 0
         * 发现，末尾多了一个0
         */

        str = stream.readAll();
        cout <<str;

        file.close();
    }
}
