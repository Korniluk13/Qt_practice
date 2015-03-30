#pragma once

#include <QWidget>
#include <QtGui>
#include <QTime>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

    public:
        explicit Widget(QWidget *parent = 0);
        ~Widget();

    private slots:
        void setGMT(bool toggled);

    private:
        Ui::Widget *ui;
        bool GMT;

    protected:
        void paintEvent(QPaintEvent *);
};
