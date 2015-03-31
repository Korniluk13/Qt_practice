#pragma once
#include <QtGui>
#include <QWidget>
#include <QPushButton>
#include <QSlider>
#include <QSpinBox>
#include <QLayout>

class ControlPanel : public QWidget
{
    Q_OBJECT
public:
    ControlPanel(QWidget *parent = 0);
    ~ControlPanel();

public:
    QPushButton *pushButton;
    QSlider *angleSlider;
    QSpinBox *velocitySpinBox;
};

