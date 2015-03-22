#include "controlPanel.h"

ControlPanel::ControlPanel(QWidget *parent) :
    QWidget(parent)
{
    QVBoxLayout *optionWindow = new QVBoxLayout;

    QFont font;
    font.setPixelSize(20);

    angleSlider = new QSlider(Qt::Horizontal);
    angleSlider->setRange(20, 70);
    angleSlider->setSliderPosition(45);
    angleSlider->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);

    velocitySpinBox = new QSpinBox;
    velocitySpinBox->setRange(50, 150);
    velocitySpinBox->setSingleStep(10);
    velocitySpinBox->setValue(100);
    velocitySpinBox->setFont(font);
    velocitySpinBox->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);

    optionWindow->addWidget(angleSlider);
    optionWindow->addWidget(velocitySpinBox);

    pushButton = new QPushButton("PUSH");
    pushButton->setFont(font);
    pushButton->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Minimum);

    QHBoxLayout *window = new QHBoxLayout;
    window->addLayout(optionWindow);
    window->addWidget(pushButton);
    setLayout(window);
}

ControlPanel::~ControlPanel()
{
    delete pushButton;
    delete angleSlider;
    delete velocitySpinBox;
}
