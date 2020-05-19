#include "widget.h"
#include "ui_widget.h"
#include <QSqlDatabase>
#include <QDebug>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QVariantList>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //打印Qt支持的数据库驱动
    qDebug() << QSqlDatabase::drivers();

    //添加MySQL数据库
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");

    //连接数据库
    db.setHostName("127.0.0.1");//数据库服务器IP
    db.setUserName("root");//数据库用户名
    db.setPassword("123456");//数据库用户密码
    db.setDatabaseName("info");//使用哪个数据库

    //打开数据库
    if(!db.open())//数据库打开失败
    {
        QMessageBox::warning(this,"错误",db.lastError().text());
        return;
    }

    QSqlQuery query;
    //直接通过sql语句创建表
    //query.exec("create table student(id int primary key auto_increment,name varchar(255),age int,score int);");

    //插入
    //query.exec("insert into student(id,name,age,score) values(1,'mike',18,59)");

    //批量插入
    //obdc风格
    /*
    //预处理语句
    // ? 相当于占位符
    query.prepare("iinsert into student(name,age,score) values(?,?,?);");
    //给字段设置内容 list
    QVariantList nameList;
    nameList << "xiaoming" << "xiaolong" << "xiangliang";
    QVariantList ageList;
    ageList << 11 << 22 << 33;
    QVariantList scoreList;
    scoreList << 59 << 69 << 79;

    //给字段绑定相应的值，按顺序绑定，否则会出问题
    query.addBindValue(nameList);
    query.addBindValue(ageList);
    query.addBindValue(scoreList);

    //执行预处理命令
    query.execBatch();
    */

    //oracle风格
    //占位符 : + 自定义名字
    query.prepare("iinsert into student(name,age,score) values(:name,:age,:score);");
    QVariantList nameList;
    nameList << "xiaoA" << "xiaoB" << "xiangC";
    QVariantList ageList;
    ageList << 21 << 12 << 43;
    QVariantList scoreList;
    scoreList << 49 << 29 << 59;
    //给字段绑定
    query.bindValue(":name",nameList);
    query.bindValue(":age",ageList);
    query.bindValue(":score",scoreList);
    //执行预处理命令
    query.execBatch();









    /****** 第二个数据库 *******/
    /*
    QSqlDatabase db1 = QSqlDatabase::addDatabase("QMYSQL","a");
    db1.setHostName("127.0.0.1");//数据库服务器IP
    db1.setUserName("root");//数据库用户名
    db1.setPassword("123456");//数据库用户密码
    db1.setDatabaseName("test");//使用哪个数据库
    if(!db1.open())//数据库打开失败
    {
        QMessageBox::warning(this,"错误",db1.lastError().text());
        return;
    }
    QSqlQuery query1(db1);
    query1.exec("create table student(id int primary key auto_increment,name varchar(255),age int,score int);");
    */


}

Widget::~Widget()
{
    delete ui;
}
