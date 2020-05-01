#include "mybutton.h"
#include <QDebug>

myButton::myButton(QWidget *parent) : QPushButton(parent)
{

}

myButton::~myButton()
{
    qDebug() << "按钮被析构";
}
