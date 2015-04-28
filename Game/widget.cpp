#include "widget.h"

Widget::Widget(QWidget *parent) :
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

    connect(mControlPanel->mStartButton, SIGNAL(clicked())
            , mGameField, SLOT(buildField()));

    connect(mControlPanel->mSizeBox, SIGNAL(valueChanged(int))
            , mGameField, SLOT(changeSize(int)));
}

Widget::~Widget()
{
    delete mGameField;
    delete mControlPanel;
}
