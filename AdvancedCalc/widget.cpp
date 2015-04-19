#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent)
  , ui(new Ui::Widget)
  , firstNumber(0)
  , secondNumber(0)
  , operation('+')
  , operationsSequense(false)
{
    ui->setupUi(this);

    //connecting figures and buttons
    const int figureCount = 10;
    QPushButton *figureButtonArray[] = {
        ui->button0
        , ui->button1
        , ui->button2
        , ui->button3
        , ui->button4
        , ui->button5
        , ui->button6
        , ui->button7
        , ui->button8
        , ui->button9
    };
    for (int i = 0; i < figureCount; i++)
    {
        figureSignalMapper.setMapping(figureButtonArray[i], static_cast<QString>(i + '0'));
        connect(figureButtonArray[i], SIGNAL(clicked()), &figureSignalMapper, SLOT(map()));
    }

    //connecting point with button
    figureSignalMapper.setMapping(ui->buttonPoint, ".");
    connect(ui->buttonPoint, SIGNAL(clicked()), &figureSignalMapper, SLOT(map()));

    //connecting operations and buttons

    const int operationCount = 4;
    QPushButton *operationButtonArray[] = {
        ui->buttonPlus
        , ui->buttonMinus
        , ui->buttonMultiplication
        , ui->buttonDivision
        };
    QString operationArray[] = {"+", "-", "*", "/"};
    for (int i = 0; i < operationCount; i++)
    {
        operationSignalMapper.setMapping(operationButtonArray[i], operationArray[i]);
        connect(operationButtonArray[i], SIGNAL(clicked()), &operationSignalMapper, SLOT(map()));
    }

    //general connection
    connect(ui->buttonResult, SIGNAL(clicked()), this, SLOT(displayResult()));
    connect(&figureSignalMapper, SIGNAL(mapped(QString)), this, SLOT(changeEditLine(QString)));
    connect(&operationSignalMapper, SIGNAL(mapped(QString)), this, SLOT(rememberOperand(QString)));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::displayResult()
{
    secondNumber = ui->lineEdit->text().toDouble();
    if (operation == '/' && secondNumber == 0)
    {
        showError("You try to divide on 0!");
        return;
    }

    const double result = Calculator::count(firstNumber, operation, secondNumber);
    ui->lineEdit->setText(QString::number(result));
    operationsSequense = false;
}

void Widget::changeEditLine(const QString &newSymbol)
{
    QString current = ui->lineEdit->text();

    if (newSymbol == "." && (static_cast<int>(current.toDouble()) != (current.toDouble())
            || current[current.length() - 1] == '.' ))
    {
        showError("Exsess point!");
        return;
    }

    current += newSymbol;
    ui->lineEdit->setText(current);
}

void Widget::rememberOperand(const QString &operation)
{
    if (operationsSequense)
    {
        secondNumber = ui->lineEdit->text().toDouble();
        firstNumber = Calculator::count(firstNumber, this->operation, secondNumber);
    }
    else
        firstNumber = ui->lineEdit->text().toDouble();

    this->operation = operation[0];
    ui->lineEdit->clear();
    operationsSequense = true;
}

void Widget::showError(const QString &error)
{
    QMessageBox errorBox;
    errorBox.setText(error);
    errorBox.show();
}
