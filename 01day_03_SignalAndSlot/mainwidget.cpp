#include "mainwidget.h"
#include <QPushButton>
#include <QDebug> // 打印

mainWidget::mainWidget(QWidget *parent)
    : QWidget(parent)
{
    //QPushButton b;
    b1.setParent(this);
    b1.setText("close");
    b1.move(100,100);

    b2 = new QPushButton(this);//注意，指针是空的，应该先分配内存
    b2->setText("我是指针按钮");

    connect(&b1,&QPushButton::pressed,this,&mainWidget::close);
    /* &b1：信号发出者，指针类型
     * &QPushButton::pressed 处理的信号， &发送者的类名::信号名字
     * this：信号接收者
     * &mainWidget::close  槽函数，信号处理函数 &接收的类名::槽函数名
     */

    /* 自定义槽，普通函数的用法
     * Qt5：任意的成员函数，普通全局函数，静态函数
     * 槽函数需要和信号一致（参数，返回值）
     * 由于信号都是没有返回值，所以槽函数一定没有返回值
     */
    connect(b2,&QPushButton::released,this,&mainWidget::mySlot);
    connect(b2,&QPushButton::released,&b1,&QPushButton::hide);//b2变身的同时，隐藏b1按钮

    b3.setParent(this);
    b3.move(300,100);
    b3.setText("切换到子窗口");

    //sub.show();//显示子窗口
    connect(&b3,&QPushButton::released,this,&mainWidget::changeWidget);
    //处理子窗口的信号
    /*
    void (subWidget::*funSignal)() = &subWidget::mySignal;
    connect(&sub,funSignal,this,&mainWidget::dealSub);
    void (subWidget::*testSignal)(int,QString) = &subWidget::mySignal;
    connect(&sub,testSignal,this,&mainWidget::dealSlot);
    */

    //Qt4信号连接
    //Qt4槽函数必须有slots关键字
    connect(&sub,SIGNAL(mySignal()),this,SLOT(dealSub()));
    connect(&sub,SIGNAL(mySignal(int,QString)),
            this,SLOT(dealSlot(int,QString)));

    //Lambda表达式，匿名函数对象
    //C++11增加的新特性，项目文件：CONFIG += c++11
    //Qt配合信号一起使用，非常方便
    QPushButton *b4 = new QPushButton(this);
    b4->setText("Lambda表达式");
    b4->move(200,200);

//    connect(b4,&QPushButton::released,
//            [b4]()//方括号[]是用来传参的
//            {
//                b4->setText("123");
//                qDebug() << "111111";
//            }
//            );
    int a=10,b=20;
//    connect(b4,&QPushButton::released,
//            // = 把外部所有局部变量、类中所有成员以值传递方式传递进来
//            //this 把类中所有成员以值传递方式传进来
//            // & 把外部所有局部变量，引用方式，使用引用时，对象不能用指针类型
//            [=]() mutable//方括号[]是用来传参的
//            {
//                b4->setText("123");
//                qDebug() << "111111";
//                qDebug() << a << b;
//                a = 11;

//            }
//            );
    connect(b4,&QPushButton::clicked,

            [=](bool isCheck)
            {
                qDebug() << isCheck;

            }
            );

    resize(400,300);//设置窗口大小
}

void mainWidget::mySlot()
{
    b2->setText("变身！");
}

void mainWidget::changeWidget()
{
    //子窗口显示
    //本窗口隐藏
    sub.show();
    this->hide();
}

void mainWidget::dealSub()
{
    sub.hide();
    this->show();
}

void mainWidget::dealSlot(int a, QString str)
{
    // str.toUtf8() -> 字节数组QByteArray
    // ……data() -> QByteArray -> char *
    qDebug() << a << str.toUtf8().data();
}
mainWidget::~mainWidget()
{

}
