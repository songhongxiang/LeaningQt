#include <QApplication>
#include <QWidget> //窗口控件基类
#include <QPushButton>//按钮基类

int main(int argc,char **argv)
{
    QApplication app(argc,argv);

    QWidget w;

    w.setWindowTitle(QString("CSDN 牛B！")); //窗口标题

    QPushButton b;
    b.setText("我是按钮~"); //设置按钮内容
    b.setParent(&w);//指定父对象
    b.move(100,100);//移动坐标

    QPushButton b1(&w);//通过构造函数传参指定父对象
    b1.setText("我是传参指定父类的按钮~");

    w.show(); // 注意要人工显示才能显示

    app.exec();
    return 0;
}
