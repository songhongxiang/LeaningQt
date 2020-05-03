#ifndef CLIENTWIDGET_H
#define CLIENTWIDGET_H

#include <QWidget>

namespace Ui {
class ClientWidget;
}

class ClientWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ClientWidget(QWidget *parent = nullptr);
    ~ClientWidget();

private:
    Ui::ClientWidget *ui;
};

#endif // CLIENTWIDGET_H
