#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget), GMT(false)
{
    ui->setupUi(this);
    connect(ui->GMT, SIGNAL(toggled(bool)), this, SLOT(setGMT(bool)));

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(10);

    setWindowTitle("Clock");
    resize(600, 600);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::setGMT(bool toggled)
{
    GMT = toggled;
}


void Widget::paintEvent(QPaintEvent *)
{
    static const QPoint hourHand[4] =
    {
        QPoint(0, 2),
        QPoint(- 40, 2),
        QPoint(- 40, - 2),
        QPoint(0, - 2.5)
    };
    static const QPoint minuteHand[4] =
    {
        QPoint(0, 1),
        QPoint(- 60, 1),
        QPoint(- 60, - 1),
        QPoint(0, - 1)
    };
    static const QPoint secondHand[4] =
    {
        QPoint(20, 0.5),
        QPoint(- 80, 0.5),
        QPoint(- 80, - 0.5),
        QPoint(20, - 0.5)
    };

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.translate(width() / 2, height() / 2);
    int side = qMin(width(), height());
    painter.scale(side / 250.0, side / 250.0);
    painter.drawEllipse(QPoint(0, 0), 99, 99);

    QTime currentTime = QTime::currentTime();
    QTime *time = nullptr;
    if (GMT)
        time = new QTime(currentTime.hour() - 3, currentTime.minute(), currentTime.second());
    else
        time = new QTime(currentTime.hour(), currentTime.minute(), currentTime.second());

    painter.setPen(Qt::black);
    painter.setBrush(Qt::black);

    painter.save();
    painter.rotate(30.0 * ((time->hour() + time->minute() / 60.0)));
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
    painter.rotate(6.0 * (time->minute() + time->second() / 60.0));
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
    painter.rotate(6.0 * time->second());
    painter.drawConvexPolygon(secondHand, 4);
    painter.restore();

    painter.setBrush(Qt::white);
    painter.setPen(Qt::black);
    painter.drawEllipse(QPoint(0,0), 3, 3);

    delete time;
}
