#include "game.h"

Game::Game(QWidget *parent) :
    QWidget(parent)
  , mGameField(new GameField)
  , mControlPanel(new ControlPanel)
{
    resize(600, 600);
    setWindowTitle("Tic-Tac-Toe");

    QVBoxLayout *window = new QVBoxLayout;
    window->addWidget(mGameField, 3);
    window->addWidget(mControlPanel, 1);
    setLayout(window);

    connect(mControlPanel->mStartButton, &QPushButton::clicked
            , mGameField, &GameField::buildField);

    ///valueChanged - overloaded function therefore
    /// you can not use new signal and slot style
    connect(mControlPanel->mSizeBox, SIGNAL(valueChanged(int))
            , mGameField, SLOT(changeSize(int)));
}

Game::~Game()
{
    delete mGameField;
    delete mControlPanel;
}
