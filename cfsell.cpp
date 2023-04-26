#include "cfsell.h"
#include "ui_cfsell.h"
#include "sell.h"
#include "ui_sell.h"
#include <QtSql>
#include "server.h"
#include <QSqlDatabase>
#include <QSqlQuery>


Cfsell::Cfsell(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Cfsell)
{
    ui->setupUi(this);
    ui->lineEdit->setText(sui->label_2->text());
}

Cfsell::~Cfsell()
{
    delete ui;
}

void Cfsell::on_lineEdit_2_textChanged(const QString &arg1)
{
    double p1 = ui->lineEdit->text().toDouble();
    double p2 = ui->lineEdit_2->text().toDouble();
    QString pf = QString::number(p1-p2,'g',25);
    ui->label->setText(pf);
}


void Cfsell::on_pushButton_clicked()
{

}

