#ifndef WIDGET_H
#define WIDGET_H

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
    /**
         * @brief displayResult display result in lineEdit after pressing button equal
         */
        void displayResult();
        /**
         * @brief changeEditLine - changing edit line after inputing new figure
         * @param symbol - new figure or point
         */
        void changeEditLine(QString symbol);
        /**
         * @brief rememberOperand - initialization firstNumber and operation
         */
        void rememberOperand(QString operation);

    private:
        Ui::Widget *ui;

        QSignalMapper *figureSignalMapper;
        QSignalMapper *operationSignalMapper;

        double firstNumber;
        double secondNumber;
        QChar operation;

        bool operationsSequense;

        void showError(QString error);
};

#endif // WIDGET_H
