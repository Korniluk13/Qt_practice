#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <QString>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget), gMT(false)
{
    ui->setupUi(this);
    connect(ui->GMT, SIGNAL(toggled(bool)), this, SLOT(setGMT(bool)));

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(100);

    setWindowTitle("Clock");
    resize(600, 600);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::setGMT(bool toggled)
{
    gMT = toggled;
}


void Widget::paintEvent(QPaintEvent *)
{
    static const QPoint hourHand[4] =
    {
        QPoint(2, 0),
        QPoint(2, -40),
        QPoint(-2, -40),
        QPoint(-2, 0)
    };
    static const QPoint minuteHand[4] =
    {
        QPoint(1, 0),
        QPoint(1, -60),
        QPoint(-1, -60),
        QPoint(-1, 0)
    };
    static const QPoint secondHand[4] =
    {
        QPoint(0.5, 20),
        QPoint(0.5, -80),
        QPoint(-0.5, -80),
        QPoint(-0.5, 20)
    };

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.translate(width() / 2, height() / 2);
    int side = qMin(width(), height());
    painter.scale(side / 250.0, side / 250.0);
    painter.drawEllipse(QPoint(0, 0), 99, 99);

    QTime time(QTime::currentTime());
    gMT ? time.setHMS(
              QTime::currentTime().hour() - 3
              , QTime::currentTime().minute()
              , QTime::currentTime().second()
              )
        : time.setHMS(
              QTime::currentTime().hour()
              , QTime::currentTime().minute()
              , QTime::currentTime().second()
              );

    painter.setPen(Qt::black);
    painter.setBrush(Qt::black);

    painter.save();
    painter.rotate(30.0 * (time.hour() + time.minute() / 60.0));
    painter.drawConvexPolygon(hourHand, 4);
    painter.restore();

    for (int i = 0; i < 12; ++i)
    {
        painter.drawLine(88, 0, 96, 0);
        painter.rotate(30.0);
    }

    painter.setPen(Qt::gray);
    painter.setBrush(Qt::gray);

    painter.save();
    painter.rotate(6.0 * (time.minute() + time.second() / 60.0));
    painter.drawConvexPolygon(minuteHand, 4);
    painter.restore();

    for (int j = 0; j < 60; j++)
    {
        if ((j % 5) != 0)
            painter.drawLine(92, 0, 96, 0);
        painter.rotate(6.0);
    }

    painter.setBrush(Qt::black);
    painter.setPen(Qt::black);
    painter.save();
    painter.rotate(6.0 * time.second());
    painter.drawConvexPolygon(secondHand, 4);
    painter.restore();

    painter.setBrush(Qt::white);
    painter.setPen(Qt::black);
    painter.drawEllipse(QPoint(0,0), 3, 3);
}
