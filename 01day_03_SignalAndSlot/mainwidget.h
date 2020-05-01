#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QPushButton>
#include "subwidget.h"

class mainWidget : public QWidget
{
    Q_OBJECT

public:
    mainWidget(QWidget *parent = 0);
    ~mainWidget();
public slots:
    void mySlot();//自定义槽函数
    void changeWidget();//
    void dealSub();
    void dealSlot(int,QString);
private:
    QPushButton b1;
    QPushButton *b2;
    QPushButton b3;

    subWidget sub;


};

#endif // MAINWIDGET_H
