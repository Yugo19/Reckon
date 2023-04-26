#include "sell.h"
#include "ui_sell.h"
#include "server.h"
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QString>
#include <QMessageBox>
//#include "cfsell.h"
#include <QPrinter>
#include <QPrintDialog>
#include <QRandomGenerator>


Sell::Sell(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Sell)
{
    ui->setupUi(this);
    setWindowTitle("Vente");

    db->connect();

    const char *query;
    query = "Select * from registred where Quantite > 0";


    QSqlQueryModel *model1 = new QSqlQueryModel;
    model1->setQuery(query);

    ui->tableView->setModel(model1);
    db->disconnect();
    ui->pushButton_3->setVisible(false);
    randG();
    randG1();

}

Sell::~Sell()
{
    delete ui;
}

void Sell::on_pushButton_clicked()
{
   db->connect();
   if(ui->checkBox->checkState()==false){


        qryD->prepare("Delete from tempells");
        qryD->exec();

        db->disconnect();

        db->connect();

        query->prepare("insert into sells values(?, ?, ?, ?, ?, ?, ?, ?)");
        query->addBindValue(ui->lineEdit->text());
        query->addBindValue(ui->lineEdit_2->text());
        query->addBindValue(ui->lineEdit_3->text());
        query->addBindValue(ui->lineEdit_5->text());
        query->addBindValue(ui->label_2->text());
        query->addBindValue(ui->dateEdit->date());
        query->addBindValue(ui->lineEdit_6->text());
        query->addBindValue(ui->lineEdit_43->text());

   if(!query->exec())
   {
       QMessageBox *msg1 = new QMessageBox;
       msg1->setText("Erreur");
       msg1->show();
   }else
   {
       QMessageBox msg;
       msg.setText("Vente enregistrer");
       msg.show();
   }
       db->disconnect();

       db->connect();
       query->prepare("insert into tempells values(?, ?, ?, ?, ?, ?, ?, ?)");
       query->addBindValue(ui->lineEdit->text());
       query->addBindValue(ui->lineEdit_2->text());
       query->addBindValue(ui->lineEdit_3->text());
       query->addBindValue(ui->lineEdit_5->text());
       query->addBindValue(ui->label_2->text());
       query->addBindValue(ui->dateEdit->date());
       query->addBindValue(ui->lineEdit_6->text());
       query->addBindValue(ui->lineEdit_43->text());

       query->exec();
       db->disconnect();

       db->connect();

       query->prepare("insert into client (Nom, Adresse, id_Ven) values(?, ?, ?)");
       query->addBindValue(ui->lineEdit_7->text());
       query->addBindValue(ui->lineEdit_8->text());
       query->addBindValue(ui->lineEdit->text());
       query->exec();

       db->disconnect();

       db->connect();
      // double r = ui->lineEdit_5->text().toInt();
       query->prepare("update registred set Quantite = Quantite - ?");
       query->addBindValue(ui->lineEdit_5->text().toInt());
       query->exec();
       db->disconnect();

       db->connect();

       query->prepare("insert into daily_sells values(?, ?, ?, ?, ?, ?, ?, ?)");
       query->addBindValue(ui->lineEdit->text());
       query->addBindValue(ui->lineEdit_2->text());
       query->addBindValue(ui->lineEdit_3->text());
       query->addBindValue(ui->lineEdit_5->text());
       query->addBindValue(ui->label_2->text());
       query->addBindValue(ui->dateEdit->date());
       query->addBindValue(ui->lineEdit_6->text());
       query->addBindValue(ui->lineEdit_43->text());

       query->exec();

       db->disconnect();
       randG();
       randG1();
       reload();
   }else
   {
       db->connect();
       qryI->prepare("insert into sells values(?, ?, ?, ?, ?, ?, ?, ?)");
       qryI->addBindValue(ui->lineEdit->text());
       qryI->addBindValue(ui->lineEdit_2->text());
       qryI->addBindValue(ui->lineEdit_3->text());
       qryI->addBindValue(ui->lineEdit_5->text());
       qryI->addBindValue(ui->label_2->text());
       qryI->addBindValue(ui->dateEdit->date());
       qryI->addBindValue(ui->lineEdit_6->text());
       query->addBindValue(ui->lineEdit_43->text());

       if(!qryI->exec()){
           QMessageBox msg;
           msg.setText("Erreur");
           msg.show();
       }else
       {
           QMessageBox msg;
           msg.setText("Enregistrer avec succès");
           msg.show();
       }
       db->disconnect();

       db->connect();

       qryI->prepare("insert into tempells values(?, ?, ?, ?, ?, ?, ?, ?)");
       qryI->addBindValue(ui->lineEdit->text());
       qryI->addBindValue(ui->lineEdit_2->text());
       qryI->addBindValue(ui->lineEdit_3->text());
       qryI->addBindValue(ui->lineEdit_5->text());
       qryI->addBindValue(ui->label_2->text());
       qryI->addBindValue(ui->dateEdit->date());
       qryI->addBindValue(ui->lineEdit_6->text());
       query->addBindValue(ui->lineEdit_43->text());

       qryI->exec();

       db->disconnect();

       db->connect();

       qryI->prepare("insert into client (Nom, Adresse,id_Ven) values(?, ?, ?)");
       qryI->addBindValue(ui->lineEdit_7->text());
       qryI->addBindValue(ui->lineEdit_8->text());
       qryI->addBindValue(ui->lineEdit->text());

       qryI->exec();

       db->disconnect();

       db->connect();
      // double r = ui->lineEdit_5->text().toInt();
       qryI->prepare("update registred set Quantite = Quantite -? where Nom = ?");
       qryI->addBindValue(ui->lineEdit_5->text().toInt());
        qryI->addBindValue(ui->lineEdit_2->text());
       qryI->exec();
       db->disconnect();

       db->connect();

       query->prepare("insert into daily_sells values(?, ?, ?, ?, ?, ?, ?, ?)");
       query->addBindValue(ui->lineEdit->text());
       query->addBindValue(ui->lineEdit_2->text());
       query->addBindValue(ui->lineEdit_3->text());
       query->addBindValue(ui->lineEdit_5->text());
       query->addBindValue(ui->label_2->text());
       query->addBindValue(ui->dateEdit->date());
       query->addBindValue(ui->lineEdit_6->text());
       query->addBindValue(ui->lineEdit_43->text());
       query->exec();

       db->disconnect();

       reload();
       randG();

   }

}


void Sell::on_tableView_doubleClicked(const QModelIndex &index)
{
    QString Index = ui->tableView->model()->data(index).toString();

    db->connect();

    query->prepare("select * from registred where id='"+Index+"' or Nom ='"+Index+"'");
    query->exec();
    while(query->next())
    {
        ui->lineEdit_2->setText(query->value(1).toString());
        ui->lineEdit_3->setText(query->value(2).toString());
        ui->lineEdit_4->setText(query->value(3).toString());

    }
    db->disconnect();

    if(ui->lineEdit_34->text() =="1")
    {
        ui->lineEdit_10->setText(ui->lineEdit_2->text());
        ui->lineEdit_11->setText(ui->lineEdit_4->text());
        ui->lineEdit_12->setText(ui->lineEdit_5->text());
    }else if (ui->lineEdit_35->text() =="1")
    {
        ui->lineEdit_15->setText(ui->lineEdit_2->text());
        ui->lineEdit_14->setText(ui->lineEdit_4->text());
        ui->lineEdit_13->setText(ui->lineEdit_5->text());

    }else if (ui->lineEdit_36->text() =="1")
    {
        ui->lineEdit_17->setText(ui->lineEdit_2->text());
        ui->lineEdit_18->setText(ui->lineEdit_4->text());
        ui->lineEdit_16->setText(ui->lineEdit_5->text());

    }else if (ui->lineEdit_37->text() =="1")
    {
        ui->lineEdit_20->setText(ui->lineEdit_2->text());
        ui->lineEdit_21->setText(ui->lineEdit_4->text());
        ui->lineEdit_19->setText(ui->lineEdit_5->text());

    }else if (ui->lineEdit_38->text() =="1")
    {
        ui->lineEdit_23->setText(ui->lineEdit_2->text());
        ui->lineEdit_24->setText(ui->lineEdit_4->text());
        ui->lineEdit_22->setText(ui->lineEdit_5->text());

    }else if (ui->lineEdit_39->text() =="1")
    {
        ui->lineEdit_26->setText(ui->lineEdit_2->text());
        ui->lineEdit_27->setText(ui->lineEdit_4->text());
        ui->lineEdit_25->setText(ui->lineEdit_5->text());

    }else if (ui->lineEdit_40->text() =="1")
    {
        ui->lineEdit_29->setText(ui->lineEdit_2->text());
        ui->lineEdit_30->setText(ui->lineEdit_4->text());
        ui->lineEdit_28->setText(ui->lineEdit_5->text());

    }else if (ui->lineEdit_41->text() =="1")
    {
        ui->lineEdit_33->setText(ui->lineEdit_2->text());
        ui->lineEdit_31->setText(ui->lineEdit_4->text());
        ui->lineEdit_32->setText(ui->lineEdit_5->text());

    }
}


void Sell::on_tableView_activated(const QModelIndex &index)
{

}


void Sell::on_lineEdit_9_textChanged(const QString &arg1)
{
    db->connect();
    const QString request0  = "select * from registred where Nom like '%"+ui->lineEdit_9->text()+"%' ";
    model1->setQuery(request0);
    ui->tableView->setModel(model1);
    db->disconnect();

}


void Sell::on_lineEdit_4_textChanged(const QString &arg1)
{
    ui->label_2->setText(ui->lineEdit_4->text());
}


void Sell::on_lineEdit_6_textChanged(const QString &arg1)
{
    double p = ui->lineEdit_4->text().toDouble();
    double r = ui->lineEdit_6->text().toDouble();
    int q = ui->lineEdit_5->text().toDouble();

    if(!(q==0))
    {
        QString pt = QString::number((p-r)*q,'g',25);
        ui->label_2->setText(pt);
    }else
    {
        QString pt = QString::number((p-r));
        ui->label_2->setText(pt);

    }

}


void Sell::on_lineEdit_5_textChanged(const QString &arg1)
{
    double p = ui->lineEdit_4->text().toDouble();
    double r = ui->lineEdit_6->text().toDouble();
    int q = ui->lineEdit_5->text().toDouble();

    if(!(q==0))
    {
        QString pt = QString::number((p-r)*q,'g',25);
        ui->label_2->setText(pt);
    }else
    {
        QString pt = QString::number((p-r));
        ui->label_2->setText(pt);

    }
}


void Sell::on_pushButton_2_clicked()
{



   if(ui->checkBox->checkState()==false)
   {
       double p = ui->lineEdit_4->text().toDouble();
       double r = ui->lineEdit_6->text().toDouble();
       int q = ui->lineEdit_5->text().toDouble();

       if(!(q==0))
       {
           QString pt = QString::number((p-r)*q,'g',25);
           ui->label_2->setText(pt);
       }else
       {
           QString pt = QString::number((p-r));
           ui->label_2->setText(pt);

       }
       ui->textEdit->setHtml(""
                             "<div class=""container"">"
                                 "<div class=""brand-section"">"
                                     "<div class=""row"">"
                                         "<div class=""col-6"">"
                                            " <h1 class=""text-white"">ENTREPRISE TRAORE ALAKANA</h1>"
                                         "</div>"
                                         "<div class=""col-6"">"
                                             "<div class=""company-details"">"
                                                 "<p class=""text-white"">Vente de matériels électriques installation d'électrité et Divers</p>"
                                                 "<p class=""text-white"">Tél: +223 79080294 / 62077147 / 76204308</p>"
                                                 "<p class=""text-white"">Au grand marché de Kirané à coté de Sahale Transport</p>"
                                             "</div>"
                                        "</div>"
                                     "</div>"
                                 "</div>"

                                 "<div class=""body-section"">"
                                    " <div class=""row"">"
                                        " <div class=""col-6"">"
                                             "<h2 class=""heading"">Facture N.:'"+ui->lineEdit_43->text()+"'</h2>"
                                            " <p class=""sub-heading""></p>"
                                            " <p class=""sub-heading"">Date : '"+ui->dateEdit->date().toString()+"'</p>"
                                             "<p class=""sub-heading"">Email Address: customer@gfmail.com </p>"
                                         "</div>"
                                        " <div class=""col-6"">"
                                           " <p class=""sub-heading"">Nom:'"+ui->lineEdit_7->text()+"'</p>"
                                            " <p class=""sub-heading"">Address:'"+ui->lineEdit_8->text()+"' </p>"
                                             "<p class=""sub-heading""></p>"
                                            "<p class=""sub-heading"">Kirané</p>"
                                         "</div>"
                                    "</div>"
                                 "</div>"

                                 "<div class=""body-section"">"
                                    "<h3 class=""heading"">Produits commandés</h3>"
                                     "<br>"
                                    "<table class=""table-bordered"">"
                                        "<thead>"
                                            "<tr>"
                                                "<th>Produit</th>"
                                                "<th class=""w-20"">Prix</th>"
                                                 "<th class=""w-20"">Quantité</th>"

                                             "</tr>"
                                         "</thead>"
                                         "<tbody>"
                                           "<tr>"
                                               "<td>   '"+ui->lineEdit_2->text()+"'   </td>"
                                                 "<td>   '"+ui->lineEdit_4->text()+"'   </td>"
                                                 "<td>   '"+ui->lineEdit_5->text()+"'   </td>"

                                           "</tr>"

                                             "<tr>"
                                                 "<td colspan=""3"" class=""text-right""></td>"
                                                 "<td></td>"
                                             "</tr>"
                                             "<tr>"
                                                 "<td colspan=""3"" class=""text-right""></td>"
                                                 "<td> 2</td>"
                                             "</tr>"
                                             "<tr>"
                                                 "<td colspan=""3"" class=""text-right"">Grand Totale</td>"
                                                 "<td>'"+ui->label_2->text()+"'FCFA</td>"
                                             "</tr>"
                                         "</tbody>"
                                     "</table>"
                                     "<br>"
                                     "<h3 class=""heading""> Status du payement: '"+ui->lineEdit_42->text()+"'</h3>"
                                     "<h3 class=""heading"">Mode de payement: Cash </h3>"
                                 "</div>"

                                 "<div class=""body-section"">"
                                     "<p>&copy; ""Copyright"" 2021 - YugoSoft. All rights reserved."
                                         "<a href=""https://" "class=""float-right""></a>"
                                     "</p>"
                                 "</div> "
                            "</div> ");

   }else
   {
       double p = ui->lineEdit_11->text().toDouble();
       double p1 = ui->lineEdit_14->text().toDouble();
       double p2 = ui->lineEdit_18->text().toDouble();
       double p3 = ui->lineEdit_21->text().toDouble();
       double p4 = ui->lineEdit_24->text().toDouble();
       double p5 = ui->lineEdit_27->text().toDouble();
       double p6 = ui->lineEdit_30->text().toDouble();
       double p7 = ui->lineEdit_31->text().toDouble();

       int q = ui->lineEdit_12->text().toDouble();
       int q1 = ui->lineEdit_13->text().toDouble();
       int q2 = ui->lineEdit_16->text().toDouble();
       int q3 = ui->lineEdit_19->text().toDouble();
       int q4 = ui->lineEdit_22->text().toDouble();
       int q5 = ui->lineEdit_25->text().toDouble();
       int q6 = ui->lineEdit_28->text().toDouble();
       int q7 = ui->lineEdit_32->text().toDouble();

        QString pt = QString::number((p+p1+p2+p3+p4+p5+p6+p7)*(q+q1+q2+q3+q4+q5+q6+q7),'g',100);

        ui->label_2->setText(pt);
       ui->textEdit->setHtml(""
                             "<div class=""container"">"
                                 "<div class=""brand-section"">"
                                     "<div class=""row"">"
                                         "<div class=""col-6"">"
                                            " <h1 class=""text-white"">ENTREPRISE TRAORE ALAKANA</h1>"
                                         "</div>"
                                         "<div class=""col-6"">"
                                             "<div class=""company-details"">"
                                                 "<p class=""text-white"">Vente de matériels électriques installation d'électrité et Divers</p>"
                                                 "<p class=""text-white"">Tél: +223 79080294 / 62077147 / 76204308</p>"
                                                 "<p class=""text-white"">Au grand marché de Kirané à coté de Sahale Transport</p>"
                                             "</div>"
                                        "</div>"
                                     "</div>"
                                 "</div>"

                                 "<div class=""body-section"">"
                                    " <div class=""row"">"
                                        " <div class=""col-6"">"
                                             "<h2 class=""heading"">Facture N.:'"+ui->lineEdit_43->text()+"'</h2>"
                                            " <p class=""sub-heading""></p>"
                                            " <p class=""sub-heading"">Date : '"+ui->dateEdit->date().toString()+"'</p>"
                                             "<p class=""sub-heading"">Email Address: customer@gfmail.com </p>"
                                         "</div>"
                                        " <div class=""col-6"">"
                                           " <p class=""sub-heading"">Nom:'"+ui->lineEdit_7->text()+"'</p>"
                                            " <p class=""sub-heading"">Address:'"+ui->lineEdit_8->text()+"' </p>"
                                             "<p class=""sub-heading""></p>"
                                            "<p class=""sub-heading"">Kirané</p>"
                                         "</div>"
                                    "</div>"
                                 "</div>"

                                 "<div class=""body-section"">"
                                    "<h3 class=""heading"">Produits commandés</h3>"
                                     "<br>"
                                    "<table class=""table-bordered"">"
                                        "<thead>"
                                            "<tr>"
                                                "<th>Produit</th>"
                                                "<th class=""w-20"">Prix</th>"
                                                 "<th class=""w-20"">Quantité</th>"

                                             "</tr>"
                                         "</thead>"
                                         "<tbody>"
                                           "<tr>"
                                               "<td>  '"+ui->lineEdit_10->text()+"'   </td>"
                                                 "<td>   '"+ui->lineEdit_11->text()+"'  </td>"
                                                 "<td>'"+ui->lineEdit_12->text()+"'</td>"

                                           "</tr>"
                                                  "<tr>"
                                                  "<td>'"+ui->lineEdit_15->text()+"'</td>"
                                                  "<td>'"+ui->lineEdit_14->text()+"'</td>"
                                                  "<td>'"+ui->lineEdit_13->text()+"'</td>"

                                               "</tr>"
                                                "<tr>"
                                                       "<td>'"+ui->lineEdit_17->text()+"'</td>"
                                                           "<td>'"+ui->lineEdit_18->text()+"'</td>"
                                                         "<td>'"+ui->lineEdit_16->text()+"'</td>"

                                                          "</tr>"
                                                    "<tr>"
                                                          "<td>'"+ui->lineEdit_20->text()+"'</td>"
                                                          "<td>'"+ui->lineEdit_21->text()+"'</td>"
                                                            "<td>'"+ui->lineEdit_19->text()+"'</td>"

                                                              "</tr>"
                                                         "<tr>"
                                                              "<td>'"+ui->lineEdit_23->text()+"'</td>"
                                                             "<td>'"+ui->lineEdit_24->text()+"'</td>"
                                                         "<td>'"+ui->lineEdit_22->text()+"'</td>"

                                                          "</tr>"
                                                                  "<tr>"
                                                             "<td>'"+ui->lineEdit_26->text()+"'</td>"
                                                              "<td>'"+ui->lineEdit_27->text()+"'</td>"
                                                               "<td>'"+ui->lineEdit_25->text()+"'</td>"

                                                                  "</tr>"
                                                                      "<tr>"
                                                                     "<td>'"+ui->lineEdit_29->text()+"'</td>"
                                                                    "<td>'"+ui->lineEdit_30->text()+"'</td>"
                                                                    "<td>'"+ui->lineEdit_28->text()+"'</td>"

                                                                     "</tr>"
                                                                      "<tr>"
                                                                      "<td>'"+ui->lineEdit_33->text()+"'</td>"
                                                                     "<td>'"+ui->lineEdit_31->text()+"'</td>"
                                                                 "<td>'"+ui->lineEdit_32->text()+"'</td>"

                                                              "</tr>"


                                             "<tr>"
                                                 "<td colspan=""3"" class=""text-right"">Sub Total</td>"
                                                 "<td> 10.XX</td>"
                                             "</tr>"
                                             "<tr>"
                                                 "<td colspan=""3"" class=""text-right"">Tax Total %1X</td>"
                                                 "<td> 2</td>"
                                             "</tr>"
                                             "<tr>"
                                                 "<td colspan=""3"" class=""text-right"">Grand TotalE</td>"
                                                 "<td>'"+ui->label_2->text()+"'FCFA</td>"
                                             "</tr>"
                                         "</tbody>"
                                     "</table>"
                                     "<br>"
                                     "<h3 class=""heading""> Status du payement: '"+ui->lineEdit_42->text()+"'</h3>"
                                     "<h3 class=""heading"">Mode de payement: Cash </h3>"
                                 "</div>"

                                 "<div class=""body-section"">"
                                     "<p>&copy; ""Copyright"" 2021 - YugoSoft. All rights reserved."
                                         "<a href=""https://" "class=""float-right""></a>"
                                     "</p>"
                                 "</div> "
                            "</div> ");

   }


   /* iw = new imprimer;
    iw->show();*/

    QPrinter printer;


    QPrintDialog dialog(&printer,this);
    if(dialog.exec() == QDialog::Rejected) return;
    ui->textEdit->print(&printer);





}


void Sell::on_pushButton_3_clicked()
{
 //iw = new imprimer;
 //iw->show();
    db->connect();
    //model = new QSqlQueryModel();
    model2->setQuery("Select * as totale from tempells");
    ui->tableView_2->setModel(model2);
    db->disconnect();

}


void Sell::on_lineEdit_13_textChanged(const QString &arg1)
{

}


void Sell::on_checkBox_stateChanged(int arg1)
{
  if(ui->checkBox->checkState()==false)
  {
      db->connect();
      qryD->prepare("Delete from tempells");
      qryD->exec();
      db->disconnect();
      double p = ui->lineEdit_4->text().toDouble();
      double r = ui->lineEdit_6->text().toDouble();
      int q = ui->lineEdit_5->text().toDouble();

      if(!(q==0))
      {
          QString pt = QString::number((p-r)*q,'g',25);
          ui->label_2->setText(pt);
      }else
      {
          QString pt = QString::number((p-r));
          ui->label_2->setText(pt);

      }
      randG();
      randG1();

  }else
  {

}
}


void Sell::randG()
{
    quint32 v = QRandomGenerator::global()->bounded(10000,900000);
    QString vr = QString::number(v);
    ui->lineEdit->setText(vr);
}

void Sell::reload()
{
    db->connect();
    model0->setQuery("select * from registred where Quantite > 0");
    ui->tableView->setModel(model0);
    db->disconnect();
}

void Sell::on_lineEdit_10_selectionChanged()
{

}


void Sell::on_lineEdit_15_selectionChanged()
{

}


void Sell::on_lineEdit_17_selectionChanged()
{

}


void Sell::on_lineEdit_20_selectionChanged()
{

}


void Sell::on_lineEdit_23_textChanged(const QString &arg1)
{

}


void Sell::on_lineEdit_26_textChanged(const QString &arg1)
{

}


void Sell::on_lineEdit_29_selectionChanged()
{

}


void Sell::on_lineEdit_33_selectionChanged()
{
}


void Sell::on_lineEdit_23_selectionChanged()
{
}


void Sell::on_lineEdit_26_selectionChanged()
{

}


void Sell::on_lineEdit_34_selectionChanged()
{
    ui->lineEdit_34->setText("1");
    ui->lineEdit_35->setText("0");
    ui->lineEdit_36->setText("0");
    ui->lineEdit_37->setText("0");
    ui->lineEdit_38->setText("0");
    ui->lineEdit_39->setText("0");
    ui->lineEdit_40->setText("0");
    ui->lineEdit_41->setText("0");
}


void Sell::on_lineEdit_35_selectionChanged()
{
    ui->lineEdit_34->setText("0");
    ui->lineEdit_35->setText("1");
    ui->lineEdit_36->setText("0");
    ui->lineEdit_37->setText("0");
    ui->lineEdit_38->setText("0");
    ui->lineEdit_39->setText("0");
    ui->lineEdit_40->setText("0");
    ui->lineEdit_41->setText("0");
}


void Sell::on_lineEdit_36_selectionChanged()
{
    ui->lineEdit_34->setText("0");
    ui->lineEdit_35->setText("0");
    ui->lineEdit_36->setText("1");
    ui->lineEdit_37->setText("0");
    ui->lineEdit_38->setText("0");
    ui->lineEdit_39->setText("0");
    ui->lineEdit_40->setText("0");
    ui->lineEdit_41->setText("0");
}


void Sell::on_lineEdit_37_selectionChanged()
{
    ui->lineEdit_34->setText("0");
    ui->lineEdit_35->setText("0");
    ui->lineEdit_36->setText("0");
    ui->lineEdit_37->setText("1");
    ui->lineEdit_38->setText("0");
    ui->lineEdit_39->setText("0");
    ui->lineEdit_40->setText("0");
    ui->lineEdit_41->setText("0");
}


void Sell::on_lineEdit_38_selectionChanged()
{
    ui->lineEdit_34->setText("0");
    ui->lineEdit_35->setText("0");
    ui->lineEdit_36->setText("0");
    ui->lineEdit_37->setText("0");
    ui->lineEdit_38->setText("1");
    ui->lineEdit_39->setText("0");
    ui->lineEdit_40->setText("0");
    ui->lineEdit_41->setText("0");
}


void Sell::on_lineEdit_39_selectionChanged()
{
    ui->lineEdit_34->setText("0");
    ui->lineEdit_35->setText("0");
    ui->lineEdit_36->setText("0");
    ui->lineEdit_37->setText("0");
    ui->lineEdit_38->setText("0");
    ui->lineEdit_39->setText("1");
    ui->lineEdit_40->setText("0");
    ui->lineEdit_41->setText("0");
}


void Sell::on_lineEdit_40_selectionChanged()
{
    ui->lineEdit_34->setText("0");
    ui->lineEdit_35->setText("0");
    ui->lineEdit_36->setText("0");
    ui->lineEdit_37->setText("0");
    ui->lineEdit_38->setText("0");
    ui->lineEdit_39->setText("0");
    ui->lineEdit_40->setText("1");
    ui->lineEdit_41->setText("0");
}


void Sell::on_lineEdit_41_selectionChanged()
{
    ui->lineEdit_34->setText("0");
    ui->lineEdit_35->setText("0");
    ui->lineEdit_36->setText("0");
    ui->lineEdit_37->setText("0");
    ui->lineEdit_38->setText("0");
    ui->lineEdit_39->setText("0");
    ui->lineEdit_40->setText("0");
    ui->lineEdit_41->setText("1");
}


void Sell::on_lineEdit_5_cursorPositionChanged(int arg1, int arg2)
{

}

void Sell::randG1()
{
    quint32 v = QRandomGenerator::global()->bounded(1000,1000000);
    QString vr = QString::number(v);
    ui->lineEdit_43->setText(vr);
}

