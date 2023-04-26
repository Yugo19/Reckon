#include "validation.h"
#include "ui_validation.h"
#include "sell.h"
#include <ui_sell.h>

Validation::Validation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Validation)
{
    ui->setupUi(this);

    ui->lineEdit->setText(sui->label_2->text());

}

Validation::~Validation()
{
    delete ui;
}
