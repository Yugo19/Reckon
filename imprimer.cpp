#include "imprimer.h"
#include "ui_imprimer.h"
#include <QtPrintSupport/QPrintDialog>
#include <QtPrintSupport/QPrinter>
#include "server.h"
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>


imprimer::imprimer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::imprimer)
{
    ui->setupUi(this);

    db->connect();
    //model = new QSqlQueryModel();
    model.setQuery("Select sum (Prix) from tempells");
    ui->tableView->setModel(&model);
    db->disconnect();
}

imprimer::~imprimer()
{
    delete ui;
}

void imprimer::on_lineEdit_textChanged(const QString &arg1)
{

}


void imprimer::on_pushButton_clicked()
{

}

