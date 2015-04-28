#pragma once

#include <QWidget>
#include <QBoxLayout>
#include "gameField.h"
#include "controlPanel.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    GameField *mGameField;
    ControlPanel *mControlPanel;
};
