#pragma once

#include <QWidget>
#include <QPoint>
#include <QPainter>
#include <QTimer>
#include <QMessageBox>
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

    ///Show message box if you hit the target
    void showWin();

    int angle;
    int velocity;

    int currentAngle;
    int currentVelocity;
    QPoint initialCoord;
    QPoint target;

    QPoint currentCoord;
    int timeFromStart;

    QTimer *timer;

    static const int targetRadius = 50;
    static const int trunkLength = 500;
    static const int trunkWidth = 100;
    static const int bombRadius = trunkWidth / 2;

protected:
    void paintEvent(QPaintEvent *);

};
