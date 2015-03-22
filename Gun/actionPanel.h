#pragma once

#include <QWidget>
#include <QPainter>
#include <QTimer>
#include <cmath>
#include "coordinates.h"

class ActionPanel : public QWidget
{
    Q_OBJECT
public:
    ActionPanel(QWidget *parent = 0);
    ~ActionPanel();

public slots:

    ///Set angle after changes in angleSlider
    void setAngle(int newAngle);

    ///Set velocity after changes in velocityComboBox
    void setVelocity(int newVelocity);

    ///Create timer after pushing
    void createTimer();

    ///Count new coordinates and update actionPanel
    void updateCoordinates();

private:
    int angle;
    int velocity;

    int currentAngle;
    int currentVelocity;
    QPoint initialCoord;

    QPoint currentCoord;
    int timeFromStart;

    QTimer *timer;

    static const int trunkLength = 500;
    static const int trunkWidth = 100;
    static const int bombRadius = trunkWidth / 2;

protected:
    void paintEvent(QPaintEvent *);

};
