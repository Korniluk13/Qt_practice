#include "coordinates.h"

QPoint Coordinates::coordTimeDependence(QPoint initialCoord, int velocity,
                                        int angle, int timeFromStart)
{
    double cosAngle = cos(angle * piAngle);
    double sinAngle = sin(angle * piAngle);

    double velocityX = velocity * cosAngle;
    double velocityY = velocity * sinAngle;

    double coordX = initialCoord.x() + timeFromStart * velocityX;
    double coordY =  - initialCoord.y() + velocityY * timeFromStart
            - accelerationG * timeFromStart * timeFromStart / 2;

    return QPoint(coordX, - coordY);
}

QPoint Coordinates::coordLengthAngle(QPoint initialCoord, int length, int angle)
{
    double cosAngle = cos(angle * piAngle);
    double sinAngle = sin(angle * piAngle);

    double coordX = initialCoord.x() + length * cosAngle;
    double coordY = - initialCoord.y() + length * sinAngle;

    return QPoint(coordX, - coordY);
}
