#include "mythread.h"
#include <QThread>
#include <QDebug>

MyThread::MyThread(QObject *parent) : QObject(parent)
{
    isStop = false;
}

void MyThread::myTimeout()
{
    while (isStop == false)
    {
        //每隔1s发一个信号
        QThread::sleep(1);
        emit mySignal();

        qDebug() << "子线程号：" <<QThread::currentThread();

        if(true == isStop)
        {
            break;
        }
    }
}

void MyThread::setFlag(bool flag)
{
    isStop = flag;
}
