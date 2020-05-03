#include "mywidget.h"
#include "ui_mywidget.h"
#include <QDebug>
#include <QKeyEvent>
#include <QTimerEvent>
#include <QCloseEvent>
#include <QMessageBox>
#include <QEvent>

myWidget::myWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::myWidget)
{
    ui->setupUi(this);

    //启动定时器
    timerID = this->startTimer(1000);//毫秒为单位，每隔1s触发一次定时器
    this->timerID2 = this->startTimer(500);

    connect(ui->pushButton,&myButton::clicked,
            [=]()
    {
       qDebug() <<"clicked 按钮被按下";
    });

    //安装过滤器
    ui->label_2->installEventFilter(this);
}

myWidget::~myWidget()
{
    delete ui;
}

void myWidget::keyPressEvent(QKeyEvent *e)
{
    qDebug() << (char)e->key();
    if(e->key() == Qt::Key_A)
    {
        qDebug() << "Qt::Key_A";
    }
}

void myWidget::timerEvent(QTimerEvent *e)
{
    if(e->timerId() == this->timerID)
    {
        static int sec = 0;
        ui->label_3->setText(QString("<center><h1>timer1 out: %1</h1></center>").arg(sec++));

        if(5 == sec)
        {
            //停止定时器
            this->killTimer(this->timerID);
        }
    }else if (e->timerId() == this->timerID2)
    {

        static int sec2 = 0;
        ui->label_2->setText(
                    QString("<center><h1>timer2 out: %1</h1></center>").arg(sec2++)
                    );
    }

}

void myWidget::closeEvent(QCloseEvent *e)
{
    int ret = QMessageBox::question(this,"question","是否关闭窗口");
    if(ret == QMessageBox::Yes)
    {
        //关闭窗口
        //处理关闭窗口事件，接收事件，事件就不会再往下传递
        e->accept();
    }
    else {
        //不关闭窗口
        //忽略事件，事件继续给父组件传递
        e->ignore();
    }
}

bool myWidget::event(QEvent *e)//不要轻易改此函数
{
    //事件分发
//    switch (e->type()) {
//    case QEvent::Close:
//        closeEvent(e);
//        break;
//    case QEvent::MouseMove:
//        mouseMoveEvent(e);
//        break;

    if(e->type() == QEvent::Timer)
    {
        //干掉计时器
        //如果返回true，事件停止传播
        QTimerEvent *env = static_cast<QTimerEvent *>(e);
        timerEvent(env);
        return true;
    }
    else if (e->type() == QEvent::KeyPress) {
        QKeyEvent *env = static_cast<QKeyEvent *>(e);
        if(env->key() == Qt::Key_B)
        {
            return  QWidget::event(e);
        }
        return true;
    }
    else {
        return QWidget::event(e);
    }

}

bool myWidget::eventFilter(QObject *obj, QEvent *e)
{
    if(obj == ui->label_2)
    {
        QMouseEvent *env = static_cast<QMouseEvent *>(e);
        //判断事件
        if(e->type() == QEvent::MouseMove)
        {
            ui->label_2->setText(QString("Mouse move:(%1,%2)").
                                 arg(env->x()).arg(env->y()));
            return  true;
        }
        else {
            return QWidget::eventFilter(obj,e);
        }
    }

        return QWidget::eventFilter(obj,e);
}
