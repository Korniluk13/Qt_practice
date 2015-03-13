#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtGui>

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

#endif // WIDGET_H
