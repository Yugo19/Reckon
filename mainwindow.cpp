#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QSqlQuery>
#include <QMessageBox>
#include "interface.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("connection");


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{

    /*QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("localhost");
    db.setUserName("Alakana");
    db.setPassword("Alakana");
    db.setDatabaseName("reckon_db");
    db.open();
    QString pass;
    query->prepare("Select Motpasse from account");
    while(query->next())
    {
        pass.append(query->value(0).toString());

    }
    db.close();
    */
    if(ui->lineEdit->text()=="ALAKANA@7908" and ui->lineEdit_2->text() =="ALAKANA")
    {
        hide();
        window = new Interface(this);
        window->show();
        //db.close();
    }else{
        QMessageBox *msg = new QMessageBox;
        msg->setText("erreur");
        msg->show();
        //db.close();
    }




}

