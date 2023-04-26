#include "interface.h"
#include "ui_interface.h"
#include "registry.h"
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include "sell.h"
#include "stock.h"

Interface::Interface(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Interface)
{
    ui->setupUi(this);
    setWindowTitle("Menu");
}

Interface::~Interface()
{
    delete ui;
}

void Interface::on_pushButton_3_clicked()
{
  sw = new Sell(this);
  sw->show();


}


void Interface::on_pushButton_2_clicked()
{
    rw = new registry(this);
    rw->show();
}


void Interface::on_pushButton_clicked()
{
    skw = new Stock(this);
    skw->show();
}

