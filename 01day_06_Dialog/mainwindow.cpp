#include "mainwindow.h"
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QDialog>
#include <QtDebug>
#include <QMessageBox>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QMenuBar *mBar = menuBar();
    setMenuBar(mBar);
    QMenu *menu = mBar->addMenu("对话框");

    QAction *p1 = menu->addAction("模态对话框");
    connect(p1,&QAction::triggered,
            [=]()
    {
        QDialog dlg;
        dlg.exec();//等待用户操作
        qDebug()<<"111111111111";//操作完会打印这句话
    });

    QAction *p2 = menu->addAction("非模态对话框");
    connect(p2,&QAction::triggered,
            [=]()
    {
       //QDialog dlg;//此种情况，运行后对话框由于没有等待用户操作，将会直接闪退，此时可将其当做类成员
       // 实现方式1:最简单
//       dlg.show();
//       qDebug()<<"22222222";
       //实现方式2:
//        QDialog *p = new QDialog(this);
//        p->show();//这种方式只有在关闭时才会释放，这就导致内部越用越少
        //实现方式3:
        QDialog *p = new QDialog;
        p->setAttribute(Qt::WA_DeleteOnClose);//关闭即释放
        p->show();
    });

    QAction *p3 = menu->addAction("关于对话框");
    connect(p3,&QAction::triggered,
            [=]()
    {
        QMessageBox::about(this,"about","关于qt");
    }
    );

    QAction *p4 = menu->addAction("问题对话框");
    connect(p4,&QAction::triggered,
            [=]()
    {
       int ret = QMessageBox::question(this,"question","are you ok?",
                                       QMessageBox::Ok,QMessageBox::Cancel);
       switch (ret) {
       case QMessageBox::Ok:
           qDebug()<<"I am ok";
           break;
       case QMessageBox::Cancel:
           qDebug()<<"I am bad";
           break;
       default:
           break;
       }
    }
    );

    QAction *p5 = menu->addAction("文件对话框");
    connect(p5,&QAction::triggered,
            [=]()
    {
        QString path = QFileDialog::getOpenFileName(
                    this,
                    "open",
                    "../",//路径设置
                    "souce(*.cpp *.h);;Text(*.txt);;all(*.*)");//过滤器，可自动换行
        qDebug() <<path;
    }
    );
}

MainWindow::~MainWindow()
{

}
