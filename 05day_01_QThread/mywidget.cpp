#include "mywidget.h"
#include "ui_mywidget.h"
#include <QThread>
#include <QDebug>

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);

    myTimer = new QTimer(this);

    //只要定时器启动，自动触发timeout信号
    connect(myTimer,&QTimer::timeout,this,&MyWidget::dealTimeout);

    //分配空间
    thread = new MyThread(this);

    connect(thread,&MyThread::isDone,this,&MyWidget::dealDone);

    //当按窗口右上角x时，窗口触发destroyed()信号
    connect(this,&MyWidget::destroyed,this,&MyWidget::stopThread);
}



void MyWidget::dealTimeout()
{
    static int i = 0;
    i++;
    //设置lcd的值
    ui->lcdNumber->display(i);
}

MyWidget::~MyWidget()
{
    delete ui;
}

void MyWidget::on_pushButton_clicked()
{
    //如果定时器没有工作，才启动
    if(myTimer->isActive() == false)
    {
        myTimer->start(500);
    }

    /***************************************
     *   未使用线程前的测试代码
     ***************************************/
    /*
    //非常复杂的数据处理，耗时较长
    //此处模拟
    QThread::sleep(3);

    //处理完数据后，关闭定时器
    //myTimer->stop();
    qDebug() <<"over";

    //什么时候用线程？
    //处理数据很复杂的时候，数据处理就应该放在线程而不是界面
    */

    //启动线程，处理数据
    thread->start();

}

void MyWidget::dealDone()
{
    qDebug() << "it is over";
    myTimer->stop();//关闭定时器

}

void MyWidget::stopThread()
{
    //停止线程
    thread->quit();
    //等待线程处理完手头工作
    thread->wait();//阻塞线程，直到线程完成
    qDebug() << "退出线程";
    /* 注释thread->wait()时，调试记录如下（线程正在执行，关闭窗口）：
     *  退出线程
     *  QThread: Destroyed while thread is still running
     *  14:19:36: The program has unexpectedly finished.
     */
}
