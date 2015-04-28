#pragma once

#include <QFrame>
#include <QBoxLayout>
#include <QSpinBox>
#include <QPushButton>

class ControlPanel : public QFrame
{
    Q_OBJECT
public:
    explicit ControlPanel(QWidget *parent = 0);

    QSpinBox *mSizeBox;
    QPushButton *mStartButton;
};

