#include "actionPanel.h"

ActionPanel::ActionPanel(QWidget *parent) :
    QWidget(parent),
    angle(45), velocity(100),
    currentAngle(45), currentVelocity(100),
    initialCoord(bombRadius, bombRadius), currentCoord(bombRadius, bombRadius),
    timeFromStart(0)
{
    timer = new QTimer(this);
    timer->stop();

    connect(timer, SIGNAL(timeout()), this, SLOT(updateCoordinates()));
}

ActionPanel::~ActionPanel()
{
    delete timer;
}

void ActionPanel::setAngle(int newAngle)
{
    angle = newAngle;
    update();
}

void ActionPanel::setVelocity(int newVelocity)
{
    velocity = newVelocity;
}

void ActionPanel::createTimer()
{
    currentCoord = Coordinates::coordLengthAngle(QPoint(0, 0), bombRadius + trunkLength, angle);
    initialCoord = currentCoord;
    currentAngle = angle;
    currentVelocity = velocity;
    timeFromStart = 0;
    timer->start(40);
}

void ActionPanel::updateCoordinates()
{
    timeFromStart++;
    currentCoord = Coordinates::coordTimeDependence(initialCoord, currentVelocity,
                                                    currentAngle, timeFromStart);
    update();
}

void ActionPanel::paintEvent(QPaintEvent *)
{
    static const QPoint trunk[4] =
    {
        QPoint (0, - trunkWidth / 2),
        QPoint (trunkLength, - trunkWidth / 2),
        QPoint (trunkLength, trunkWidth / 2),
        QPoint (0, trunkWidth / 2)
    };

    QColor trunkColor(Qt::darkGray);

    QPainter painter(this);
    painter.translate(0, height());
    int side = qMax(width(), height());
    painter.scale(side / 2000.0, side / 2000.0);

    painter.setBrush(trunkColor);
    painter.setPen(Qt::black);
    painter.save();
    painter.rotate(- angle);
    painter.drawConvexPolygon(trunk, 4);
    painter.restore();
    painter.drawEllipse(QPoint(0, 0), trunkLength / 2, trunkLength / 2);

    painter.drawEllipse(currentCoord, bombRadius, bombRadius);
}
