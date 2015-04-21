#pragma once

#include <QWidget>
#include <QBoxLayout>
#include "actionPanel.h"
#include "controlPanel.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

private:
    ControlPanel *controlPanel;
    ActionPanel *actionPanel;
};

