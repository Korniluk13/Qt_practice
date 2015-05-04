#pragma once

#include <QFrame>
#include <QBoxLayout>
#include <QSpinBox>
#include <QPushButton>

///Class provides control panel for the game
class ControlPanel : public QFrame
{
    Q_OBJECT
public:
    explicit ControlPanel(QWidget *parent = 0);

    ~ControlPanel() override;

    //Has ownership
    QSpinBox *mSizeBox;

    //Has ownership
    QPushButton *mStartButton;
};

