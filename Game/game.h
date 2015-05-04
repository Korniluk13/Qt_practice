#pragma once

#include <QWidget>
#include <QBoxLayout>
#include "gameField.h"
#include "controlPanel.h"

class Game : public QWidget
{
    Q_OBJECT

public:
    explicit Game(QWidget *parent = 0);
    ~Game();

private:
    //Has ownership
    GameField *mGameField;

    //Has ownership
    ControlPanel *mControlPanel;
};
