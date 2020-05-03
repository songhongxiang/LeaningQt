#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QStringList>
#include <QCompleter>
#include <QMovie>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //获取内容
    QString str = ui->lineEdit->text();
    qDebug() << str ;

    //设置内容
    ui->lineEdit->setText("654321");

    //设置内容显示间隙
    ui->lineEdit->setTextMargins(15,0,0,0);

    //设置内容显示方式
//    ui->lineEdit->setEchoMode(QLineEdit::Password);

    // 内容提示框
    QStringList list;
    list << "Hello" << "how are you" << "test";

    QCompleter *com = new QCompleter(list,this);
    com->setCaseSensitivity(Qt::CaseInsensitive);
    ui->lineEdit->setCompleter(com);

    //QLabel
    //设置文本内容
    ui->labelText->setText("^_^");

    //设置图片
    ui->labelImage->setPixmap(QPixmap("://Image/image2.png"));

    //让图片自动适应大小
    ui->labelImage->setScaledContents(true);

    //创建动画
    QMovie *myMovie = new QMovie("://Image/dog.gif");

    //设置动画
    ui->labelGif->setMovie(myMovie);
    //启动动画
    myMovie->start();
    ui->labelGif->setScaledContents(true);


    //设置html
    ui->labelUrl->setText("<h1><a href=\"www.baidu.com\">百度一下</a></h1>");
    ui->labelUrl->setOpenExternalLinks(true);

    //数码控
    ui->lcdNumber->display(123);

    //进度条
    ui->progressBar->setMinimum(0);//最小值
    ui->progressBar->setMaximum(100);//最大值
    ui->progressBar->setValue(15);//当前值
}

MainWindow::~MainWindow()
{
    delete ui;
}
