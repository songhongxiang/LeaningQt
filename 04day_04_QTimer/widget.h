#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer> //定时器对象

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_buttonStart_clicked();

    void on_buttonStop_clicked();

private:
    Ui::Widget *ui;
    QTimer *myTimer;//定时器对象
};

#endif // WIDGET_H
