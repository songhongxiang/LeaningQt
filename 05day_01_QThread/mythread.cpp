#include "mythread.h"

MyThread::MyThread(QObject *parent) : QThread(parent)
{

}

void MyThread::run()
{
    //很复杂的数据处理
    //需要耗时5s
    sleep(5); //处理完了需要告诉一声：已经处理完了
    emit isDone();

}
