#include "controlPanel.h"

ControlPanel::ControlPanel(QWidget *parent) :
    QFrame(parent)
  , mSizeBox(new QSpinBox)
  , mStartButton(new QPushButton("Start"))
{
    setFrameShape(Panel);
    QFont font;
    font.setPixelSize(20);

    mSizeBox->setRange(3, 8);
    mSizeBox->setSingleStep(1);
    mSizeBox->setValue(3);
    mSizeBox->setFont(font);

    mStartButton->setFont(font);

    QHBoxLayout *panelLayout = new QHBoxLayout;
    panelLayout->addWidget(mSizeBox);
    panelLayout->addWidget(mStartButton);
    setLayout(panelLayout);
}
