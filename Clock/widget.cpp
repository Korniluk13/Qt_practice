#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent), GMT(false),
    ui(new Ui::Widget)
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
    static const QPoint hourHand[3] =
    {
        QPoint(7, 8),
        QPoint(-7, 8),
        QPoint(0, -40)
    };
    static const QPoint minuteHand[3] =
    {
        QPoint(7, 8),
        QPoint(-7, 8),
        QPoint(0, -60)
    };
    static const QPoint secondHand[3] =
    {
        QPoint(3, 8),
        QPoint(-3, 8),
        QPoint(0, -80)
    };

    QColor handsColor(Qt::darkRed);
    //QColor backgroundColor(Qt::black);
    int side = qMin(width(), height());

    QPainter painter(this);
    //painter.fillRect(rect(), backgroundColor);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.translate(width() / 2, height() / 2);
    painter.scale(side / 200.0, side / 200.0);


    QTime currentTime = QTime::currentTime();
    QTime *time;
    if (GMT)
        time = new QTime(currentTime.hour() - 3, currentTime.minute(), currentTime.second());
    else
        time = new QTime(currentTime.hour(), currentTime.minute(), currentTime.second());
    painter.setPen(Qt::NoPen);
    painter.setBrush(handsColor);

    painter.save();
    painter.rotate(30.0 * ((time->hour() + time->minute() / 60.0)));
    painter.drawConvexPolygon(hourHand, 3);
    painter.restore();

    painter.setPen(handsColor);

    for (int i = 0; i < 12; ++i)
    {
        painter.drawLine(88, 0, 96, 0);
        painter.rotate(30.0);
    }

    painter.save();
    painter.rotate(6.0 * (time->minute() + time->second() / 60.0));
    painter.drawConvexPolygon(minuteHand, 3);
    painter.restore();

    painter.setPen(handsColor);

    for (int j = 0; j < 60; j++)
    {
        if ((j % 5) != 0)
            painter.drawLine(92, 0, 96, 0);
        painter.rotate(6.0);
    }

    painter.save();
    painter.rotate(6.0 * time->second());
    painter.drawConvexPolygon(secondHand, 3);
    painter.restore();
}
