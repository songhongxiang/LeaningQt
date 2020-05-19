#include "mywidget.h"
#include "ui_mywidget.h"
#include <QDebug>

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);

    //动态分配空间，不能指定父对象
    myT = new MyThread;

    //创建子线程
    thread = new QThread(this);

    //把自定义的线程加入子线程中
    myT->moveToThread(thread);

    connect(myT,&MyThread::mySignal,this,&MyWidget::dealSignal);

    qDebug() << "主线程号：" <<QThread::currentThread();

    connect(this,&MyWidget::startThread,myT,&MyThread::myTimeout);

    connect(this,&MyWidget::destroyed,this,&MyWidget::dealClose);

    // 线程处理函数内部，不允许操作图形界面
    // 纯数据处理，在后台运行！！


    //connect()第五个参数的作用，只有在多线程时才有意义
    // 连接方式：默认，队列，直接
    // 默认的时候：如果是多线程，默认使用队列；如果单线程，默认使用直接方式
    // 队列：槽函数所在的线程和接收者一样
    // 直接：槽函数所在线程和发送者一样

}

MyWidget::~MyWidget()
{
    delete ui;
}

void MyWidget::on_butttonStart_clicked()
{
    if(thread->isRunning() == true)
    {
        return;
    }
    //启动线程，但是没有线程处理函数
    thread->start();
    myT->setFlag(false);

    // 不能直接调用线程处理函数
    // 直接调用会导致：线程处理函数和主线程是在同一个线程
    //myT->myTimeout();//反例

    //只能通过signal - slot 方式调用
    emit startThread();


}

void MyWidget::dealSignal()
{
    static int i = 0;
    i++;
    ui->lcdNumber->display(i);
}

void MyWidget::on_buttonStop_clicked()
{
    if(thread->isRunning() == false)
    {
        return;
    }

    // 由于quit()退出线程的方式很温柔，
    // 而且线程的工作是个死循环，退不出来，因此这种方法不可行
    // 解决方案：在while(1)中加入一个标志位
    myT->setFlag(true);
    thread->quit();
    thread->wait();


}


void MyWidget::dealClose()
{
    //槽函数就是函数，可以直接调
    on_buttonStop_clicked();

    delete myT;//防止内存泄露
}
