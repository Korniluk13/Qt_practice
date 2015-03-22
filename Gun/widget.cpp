#include "widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent)
{
    controlPanel = new ControlPanel;
    actionPanel = new ActionPanel;

    QVBoxLayout *window = new QVBoxLayout;
    window->addWidget(actionPanel, 3);
    window->addWidget(controlPanel, 1);
    setLayout(window);
    resize(500, 500);

    connect(controlPanel->angleSlider, SIGNAL(valueChanged(int)),
            actionPanel, SLOT(setAngle(int)));

    connect(controlPanel->velocitySpinBox, SIGNAL(valueChanged(int)),
            actionPanel, SLOT(setVelocity(int)));

    connect(controlPanel->pushButton, SIGNAL(clicked()),
            actionPanel, SLOT(createTimer()));
}

Widget::~Widget()
{
    delete controlPanel;
    delete actionPanel;
}
