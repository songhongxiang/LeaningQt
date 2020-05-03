#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    myTimer = new QTimer(this);
    connect(myTimer,&QTimer::timeout,
            [=]()
    {
        static int i=0;
        ui->lcdNumber->display(i++);
    });

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_buttonStart_clicked()
{
    //启动定时器
    //时间间隔为500ms
    //每隔500ms，定时器myTimer自动触发timeout()
    if(myTimer->isActive() == false)
    {
        //如果定时器没有激活才启动
        myTimer->start(500);
    }

}

void Widget::on_buttonStop_clicked()
{
    if(myTimer->isActive() == true)
    {
        //如果定时器是活动的才会关闭
        myTimer->stop();
    }
}
