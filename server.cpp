#include "server.h"
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
Server::Server()
{  
    db = new QSqlDatabase(QSqlDatabase::addDatabase(drivername));
    query = new QSqlQuery;
}

void Server::connect()
{

    db->setHostName("localhost");
    db->setDatabaseName("reckon_db");
    db->setUserName("postgres");
    db->setPassword("Maoene");

   if(!db->open()){
       QMessageBox msg;
       msg.setText("Erreur");
       msg.show();
   }

}

void Server::disconnect()
{

  db->close();
}

void Server::executequeries(const char *request)
{
    query->prepare(request);
}
