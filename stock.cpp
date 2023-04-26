#include "stock.h"
#include "ui_stock.h"
#include"server.h"
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>

Stock::Stock(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Stock)
{
    ui->setupUi(this);
    setWindowTitle("Gestion des stocks");

     db = new Server;
     model = new QSqlQueryModel;

     db->connect();
     model->setQuery(request1);
     ui->tableView_2->setModel(model);


     model2->setQuery(request2);
     ui->tableView_3->setModel(model2);

     db->disconnect();

     db->connect();
     //query->prepare("select sum (Prix) from registred");
     model5->setQuery("Select sum (Prix) as totale, sum (Quantite) as Nombre_de_produit from registred");
     ui->tableView_4->setModel(model5);
     db->disconnect();

     ui->lineEdit_9->setVisible(false);
     ui->lineEdit_3->setVisible(false);
     ui->lineEdit_4->setVisible(false);
     ui->lineEdit_5->setVisible(false);
     ui->lineEdit_6->setVisible(false);
     ui->lineEdit_7->setVisible(false);
     ui->lineEdit_8->setVisible(false);
     ui->comboBox->setVisible(false);
     ui->dateEdit_5->setVisible(false);

     db->connect();
     //query->prepare("select sum (Prix) from registred");
     model8->setQuery("Select sum (Prix) as totale, sum (Quantite) as Nombre_de_produit from sells");
     ui->tableView_6->setModel(model8);
     db->disconnect();

     db->connect();
     model4->setQuery(request4);
     ui->tableView->setModel(model4);
     db->disconnect();

     db->connect();
     model9->setQuery("select sum(Prix) as Totale_du_jour from daily_sells");
     ui->tableView_7->setModel(model9);
     db->disconnect();

}

Stock::~Stock()
{
    delete ui;
}

void Stock::on_tabWidget_currentChanged(int index)
{
   db->connect();
   model4->setQuery(request4);
   ui->tableView->setModel(model4);
   db->disconnect();
}


void Stock::on_comboBox_currentTextChanged(const QString &arg1)
{
    if(ui->comboBox->currentText()=="Base 2")
    {
        db->connect();
        model3->setQuery(request3);
        ui->tableView->setModel(model3);
        db->disconnect();
    }else if(ui->comboBox->currentText() =="Base 2")
    {
        db->connect();
        model4->setQuery(request4);
        ui->tableView->setModel(model4);

        db->disconnect();
    }

}

void Stock::on_lineEdit_2_textChanged(const QString &arg1)
{
    if(ui->comboBox->currentText() =="Base 2")
    {
        db->connect();
        const QString request0  = "select * from sells where Nom like '%"+ui->lineEdit_2->text()+"%'";
        model1->setQuery(request0);
        ui->tableView->setModel(model1);
        db->disconnect();

    }else if(ui->comboBox->currentText() =="Base 2")
    {
        db->connect();
        const QString request0  = "select * from sells where Nom like '%"+ui->lineEdit_2->text()+"%' ";
        model1->setQuery(request0);
        ui->tableView->setModel(model1);
        db->disconnect();
    }
}


void Stock::on_pushButton_2_clicked()
{
    db->connect();
    const QString request0  = "select * from sells where DateVen between '"+ui->dateEdit_3->date().toString()+"' and '"+ui->dateEdit_4->date().toString()+"' ";
    model1->setQuery(request0);
    ui->tableView_2->setModel(model1);
    db->disconnect();

}

void Stock::on_tableView_doubleClicked(const QModelIndex &index)
{

    if(ui->comboBox->currentText()=="Base 2")
    {
        db->connect();
        QString Index = ui->tableView->model()->data(index).toString();
        QSqlQuery *addquery = new QSqlQuery;
        addquery->prepare("select * from sells where id_Ven='"+Index+"' or Nom ='"+Index+"'");

        if(addquery->exec()){
            while (addquery->next()) {
                ui->lineEdit_9->setText(addquery->value(0).toString());
                ui->label_7->setText(addquery->value(1).toString());
                ui->label_8->setText(addquery->value(3).toString());
                ui->lineEdit_3->setText(addquery->value(1).toString());
                ui->lineEdit_5->setText(addquery->value(2).toString());
                ui->lineEdit_4->setText(addquery->value(3).toString());
                ui->lineEdit_6->setText(addquery->value(4).toString());
                ui->dateEdit_5->setDate(addquery->value(5).toDate());
                ui->lineEdit_8->setText(addquery->value(6).toString());
            }
           db->disconnect();


        }



    }else if(ui->comboBox->currentText() =="Base 2")
       {
        db->connect();

        QString Index = ui->tableView->model()->data(index).toString();
        QSqlQuery *addquery = new QSqlQuery;
        addquery->prepare("select * from sells where id_Ven='"+Index+"' or Nom ='"+Index+"'");

        if(addquery->exec()){
            while (addquery->next()) {
                ui->lineEdit_9->setText(addquery->value(0).toString());
                ui->label_7->setText(addquery->value(1).toString());
                ui->label_8->setText(addquery->value(3).toString());
                ui->lineEdit_3->setText(addquery->value(1).toString());
                ui->lineEdit_5->setText(addquery->value(2).toString());
                ui->lineEdit_4->setText(addquery->value(3).toString());
                ui->lineEdit_6->setText(addquery->value(4).toString());
                ui->dateEdit_5->setDate(addquery->value(5).toDate());
                ui->lineEdit_8->setText(addquery->value(6).toString());
            }
           db->disconnect();

        }



    }




}


void Stock::on_lineEdit_textChanged(const QString &arg1)
{
    db->connect();
    const QString request0  = "select * from registred where Nom like '%"+ui->lineEdit->text()+"%' ";
    model->setQuery(request0);
    ui->tableView->setModel(model);

    db->disconnect();

}


void Stock::on_pushButton_3_clicked()
{

    db->connect();

    query3->prepare("Delete from daily_sells");
    query3->exec();

    db->disconnect();

}


void Stock::on_lineEdit_9_textChanged(const QString &arg1)
{
    if(ui->comboBox->currentText() =="Base 2")
    {

        db->connect();

        model6->setQuery("select * from client where id_Ven ='"+ui->lineEdit_9->text()+"'");
       // query3->executedQuery();
        ui->tableView_5->setModel(model6);

        db->disconnect();

    }else if(ui->comboBox->currentText() =="Base 2"){

        db->connect();

        model7->setQuery("select * from client where id_Ven ='"+ui->lineEdit_9->text()+"'");
       // query3->executedQuery();
        ui->tableView_5->setModel(model7);

    }

}


void Stock::on_pushButton_4_clicked()
{
    db->connect();
    model10->setQuery("Delete from daily_sells");
    ui->tableView_7->setModel(model10);
    db->disconnect();

}

