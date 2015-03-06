#pragma once
#include <QWidget>
#include <QPushButton>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
     Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;
};
