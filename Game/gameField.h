#pragma once

#include <QFrame>
#include <QGridLayout>
#include <QPushButton>

///Class draws game field and provides its
class GameField : public QFrame
{
    Q_OBJECT
public:
    explicit GameField(QWidget *parent = 0);
    ~GameField() override;

public slots:

    ///Change size of the field
    void changeSize(int size);

    ///Building the field using current size of the field
    /// after start button pressing
    void buildField();

    ///Change button after clicking
    void changeButton();

private:
    ///Deleting all objects from the layout
    void clearLayout(QLayout *layout);

    int mFieldSize;
    bool mNextStepX;

    //Has ownership
    QGridLayout *buttonLayout;
};
