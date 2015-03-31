#pragma once

#include <QPoint>
#include <cmath>

class Coordinates
{
public:

    ///Count coordinates of the object using initial coordinates,
    /// using the angle of the throw, velocity of the throw,
    /// time from start throwing
    static QPoint coordTimeDependence(
            QPoint initialCoord
            , int velocity
            , int angle
            , int timeFromStart
            );

    ///Count coordinates using initial coordinates, distance between current point
    /// and initial coordinates, tilt angle
    static QPoint coordLengthAngle(
            QPoint initialCoord
            , int length
            , int angle
            );

    ///Determine is object in circle or not
    static bool inCircle(
            QPoint centerOfObject
            , QPoint centerOfCircle
            , int circleRadius
            );

private:
    static const double piAngle = 3.14 / 180.0;
    static const int accelerationG = 9.8;
};

