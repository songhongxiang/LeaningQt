#include "widget.h"
#include "ui_widget.h"
#include "domxml.h"
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    DomXml::createXML("../demo.xml");

    QStringList list;
    list << "二汽神龙" << "毕加索" << "39" << "1" << "39";
    DomXml::appendXML("../demo.xml",list);


    QStringList fList,bList,pList,nList,tList;
    DomXml::readXML("../demo.xml",fList,bList,pList,nList,tList);
    for (int i = 0;i < fList.size(); i++)
    {
        QString str = QString("%1:%2:卖出了%3，单价：%4，总价：%5")
                .arg(fList.at(i))
                .arg(bList.at(i))
                .arg(pList.at(i))
                .arg(nList.at(i))
                .arg(tList.at(i));

        qDebug() << str;
    }
}

Widget::~Widget()
{
    delete ui;
}
