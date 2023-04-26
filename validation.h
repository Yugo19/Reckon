#ifndef VALIDATION_H
#define VALIDATION_H

#include <QDialog>
#include "sell.h"
#include "ui_sell.h"

namespace Ui {
class Validation;
}

class Validation : public QDialog
{
    Q_OBJECT

public:
    explicit Validation(QWidget *parent = nullptr);
    ~Validation();

private:
    Ui::Validation *ui;
    //Sell *sui = new Sell;
    Ui_Sell *sui = new Ui_Sell;
};

#endif // VALIDATION_H
