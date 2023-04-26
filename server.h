#ifndef SERVER_H
#define SERVER_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
class Server
{
public:
    Server();
    void connect();
    void disconnect();
    void executequeries(const char *request);
    const char *drivername = "QPSQL";


private:
    QSqlDatabase *db;
    QSqlQuery *query;
};

#endif // SERVER_H
