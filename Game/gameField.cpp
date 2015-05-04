#include "gameField.h"

GameField::GameField(QWidget *parent) :
    QFrame(parent)
  , mFieldSize(3)
  , mNextStepX(true)
  , buttonLayout(new QGridLayout)
{
    setFrameShape(Box);
}

GameField::~GameField()
{
    clearLayout(buttonLayout);
}

void GameField::changeSize(int size)
{
    mFieldSize = size;
}

void GameField::buildField()
{
    clearLayout(buttonLayout);

    for (int i = 0; i < mFieldSize; i++)
    {
        for (int j = 0; j < mFieldSize; j++)
        {
            QPushButton * const button = new QPushButton();
            button->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);

            connect(button, SIGNAL(clicked()), this, SLOT(changeButton()));

            buttonLayout->addWidget(button, i, j);
        }
    }
    setLayout(buttonLayout);
}

void GameField::changeButton()
{
    const auto button = static_cast<QPushButton *>(QObject::sender());
    button->setDisabled(true);

    mNextStepX ? button->setIcon(QIcon("x.png"))
               : button->setIcon(QIcon("o.png"));

    mNextStepX = !mNextStepX;
}

void GameField::clearLayout(QLayout *layout)
{
    QLayoutItem *child = nullptr;
    while ((child = layout->takeAt(0)) != nullptr)
    {
        if (child->layout() != nullptr)
            clearLayout(child->layout());
        else
            delete child->widget();

        delete child;
    }
}
