#pragma once

#include <QWidget>
#include <QSignalMapper>
#include <QMessageBox>
#include "calculator.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    ///displayResult display result in lineEdit after pressing button equal
    void displayResult();

    ///changeEditLine - changing edit line after inputing new figure
    void changeEditLine(const QString &newSymbol);

    ///initialization firstNumber and operation
    void rememberOperand(const QString &operation);

private:
    Ui::Widget *ui;

    QSignalMapper figureSignalMapper;
    QSignalMapper operationSignalMapper;

    double firstNumber;
    double secondNumber;
    QChar operation;
    bool operationsSequense;

    ///Show message box with text of the error
    void showError(const QString &error);
};
