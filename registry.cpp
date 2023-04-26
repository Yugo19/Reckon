#include "registry.h"
#include "ui_registry.h"
#include <QMessageBox>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "server.h"

registry::registry(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::registry)
{
    ui->setupUi(this);
    setWindowTitle("Enregistrement de produits");


    QMessageBox msg;

    db->connect();


    QSqlQueryModel *model1 = new QSqlQueryModel;
    model1->setQuery("Select * from registred");

    ui->tableView->setModel(model1);
    db->disconnect();

}


registry::~registry()
{
    delete ui;
}

void registry::on_tableView_doubleClicked(const QModelIndex &index)
{
        db->connect();
        QString Index = ui->tableView->model()->data(index).toString();
        QSqlQuery *addquery = new QSqlQuery;
        addquery->prepare("select * from registred where id='"+Index+"' or Nom ='"+Index+"'");

        if(addquery->exec()){
            while (addquery->next()) {
                ui->lineEdit->setText(addquery->value(1).toString());
                ui->lineEdit_2->setText(addquery->value(2).toString());
                ui->lineEdit_3->setText(addquery->value(3).toString());
                ui->lineEdit_4->setText(addquery->value(4).toString());
                ui->dateEdit->setDate(addquery->value(5).toDate());
            }
           db->disconnect();
        }

}





void registry::on_pushButton_clicked()
{

        db->connect();

        QSqlQuery *addquery = new QSqlQuery;
        addquery->prepare("insert into registred(Nom, Categorie, Prix, Quantite, DateEn) values(?, ?, ?, ?, ?)");
        addquery->addBindValue(ui->lineEdit->text());
        addquery->addBindValue(ui->lineEdit_2->text());
        addquery->addBindValue(ui->lineEdit_3->text());
         addquery->addBindValue(ui->lineEdit_4->text());
        addquery->addBindValue(ui->dateEdit->date());


        if(addquery->exec()){
            QMessageBox msg2;
            msg2.setText("Enregistrer");
            msg2.show();
            db->disconnect();
        }else {
            QMessageBox msg3;
            msg3.setText("Echec");
            msg3.show();
            db->disconnect();


}

         reload();
}



void registry::on_pushButton_2_clicked()
{

        db->connect();
        QSqlQuery *addquery = new QSqlQuery;
        addquery->prepare("update registred set Nom = ? , Categorie = ?, Prix = ?, Quantite = Quantite +?, DateEn = ? where Nom = ?");
        addquery->addBindValue(ui->lineEdit->text());
        addquery->addBindValue(ui->lineEdit_2->text());
        addquery->addBindValue(ui->lineEdit_3->text());
        addquery->addBindValue(ui->lineEdit_4->text().toInt());
        addquery->addBindValue(ui->dateEdit->date());
        addquery->addBindValue(ui->lineEdit->text());
      //addquery->addBindValue(ui->dateEdit->date()); to be changed for update

        if(addquery->exec()){
            QMessageBox msg2;
            msg2.setText("Mise à jour avec succès");
            msg2.show();
            db->disconnect();
        }else {
            QMessageBox *msg3 = new QMessageBox;
            msg3->setText("echec");
            msg3->show();
            db->disconnect();

}
        reload();

}


void registry::on_pushButton_3_clicked()
{
        db->connect();


        QSqlQuery *addquery = new QSqlQuery;
        addquery->prepare("delete from registred where Nom = ?");
        addquery->addBindValue(ui->lineEdit->text());


        if(addquery->exec()){
            QMessageBox msg2;
            msg2.setText("Enregistrer");
            msg2.show();
            db->disconnect();
        }else {
            QMessageBox msg3;
            msg3.setText("Echec");
            msg3.show();
            db->disconnect();

}
        reload();

}

void registry::reload()
{
    db->connect();
    model0->setQuery("select * from registred");
    ui->tableView->setModel(model0);
    db->disconnect();
}

