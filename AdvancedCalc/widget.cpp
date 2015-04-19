#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent), firstNumber(0), secondNumber(0), operation('+'), operationsSequense(false),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    figureSignalMapper = new QSignalMapper(this);

    figureSignalMapper->setMapping(ui->button0, "0");
    figureSignalMapper->setMapping(ui->button1, "1");
    figureSignalMapper->setMapping(ui->button2, "2");
    figureSignalMapper->setMapping(ui->button3, "3");
    figureSignalMapper->setMapping(ui->button4, "4");
    figureSignalMapper->setMapping(ui->button5, "5");
    figureSignalMapper->setMapping(ui->button6, "6");
    figureSignalMapper->setMapping(ui->button7, "7");
    figureSignalMapper->setMapping(ui->button8, "8");
    figureSignalMapper->setMapping(ui->button9, "9");
    figureSignalMapper->setMapping(ui->buttonPoint, ".");

    connect(ui->button0, SIGNAL(clicked()), figureSignalMapper, SLOT(map()));
    connect(ui->button1, SIGNAL(clicked()), figureSignalMapper, SLOT(map()));
    connect(ui->button2, SIGNAL(clicked()), figureSignalMapper, SLOT(map()));
    connect(ui->button3, SIGNAL(clicked()), figureSignalMapper, SLOT(map()));
    connect(ui->button4, SIGNAL(clicked()), figureSignalMapper, SLOT(map()));
    connect(ui->button5, SIGNAL(clicked()), figureSignalMapper, SLOT(map()));
    connect(ui->button6, SIGNAL(clicked()), figureSignalMapper, SLOT(map()));
    connect(ui->button7, SIGNAL(clicked()), figureSignalMapper, SLOT(map()));
    connect(ui->button8, SIGNAL(clicked()), figureSignalMapper, SLOT(map()));
    connect(ui->button9, SIGNAL(clicked()), figureSignalMapper, SLOT(map()));
    connect(ui->buttonPoint, SIGNAL(clicked()), figureSignalMapper, SLOT(map()));


    operationSignalMapper = new QSignalMapper(this);
    operationSignalMapper->setMapping(ui->buttonDivision, "/");
    operationSignalMapper->setMapping(ui->buttonMinus, "-");
    operationSignalMapper->setMapping(ui->buttonMultiplication, "*");
    operationSignalMapper->setMapping(ui->buttonPlus, "+");

    connect(ui->buttonDivision, SIGNAL(clicked()), operationSignalMapper, SLOT(map()));
    connect(ui->buttonMinus, SIGNAL(clicked()), operationSignalMapper, SLOT(map()));
    connect(ui->buttonMultiplication, SIGNAL(clicked()), operationSignalMapper, SLOT(map()));
    connect(ui->buttonPlus, SIGNAL(clicked()), operationSignalMapper, SLOT(map()));

    connect(ui->buttonResult, SIGNAL(clicked()), this, SLOT(displayResult()));
    connect(figureSignalMapper, SIGNAL(mapped(QString)), this, SLOT(changeEditLine(QString)));
    connect(operationSignalMapper, SIGNAL(mapped(QString)), this, SLOT(rememberOperand(QString)));
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
