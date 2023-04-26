#ifndef STOCK_H
#define STOCK_H

#include <QDialog>
#include "server.h"
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>

namespace Ui {
class Stock;
}

class Stock : public QDialog
{
    Q_OBJECT

public:
    explicit Stock(QWidget *parent = nullptr);
    ~Stock();
    const char *request2 = "Select * from registred where Quantite < 5";
    const char *request1 = "Select * from registred";
    const char *request4 = "Select * from sells";
    const char *request3 = "Select * from daily_sells";

private slots:
    void on_tabWidget_currentChanged(int index);

    void on_comboBox_currentTextChanged(const QString &arg1);

    void on_lineEdit_2_textChanged(const QString &arg1);

    void on_pushButton_2_clicked();

    void on_tableView_doubleClicked(const QModelIndex &index);

    void on_lineEdit_textChanged(const QString &arg1);

    void on_pushButton_3_clicked();

    void on_lineEdit_9_textChanged(const QString &arg1);

    void on_pushButton_4_clicked();

private:
    Ui::Stock *ui;
    Server *db;
    QSqlQuery *query = new QSqlQuery;
    QSqlQueryModel *model =  new QSqlQueryModel;
    QSqlQueryModel *model1 =  new QSqlQueryModel;
    QSqlQueryModel *model2 = new QSqlQueryModel;
    QSqlQueryModel *model3 = new QSqlQueryModel;
    QSqlQueryModel *model4 = new QSqlQueryModel;
    QSqlQueryModel *model5 = new QSqlQueryModel;
    QSqlQueryModel *model6 = new QSqlQueryModel;
    QSqlQueryModel *model7 = new QSqlQueryModel;
    QSqlQueryModel *model8 = new QSqlQueryModel;
    QSqlQueryModel *model9 = new QSqlQueryModel;
    QSqlQueryModel *model10 = new QSqlQueryModel;

    QSqlQuery *query2 = new QSqlQuery;
    QSqlQuery *query3 = new QSqlQuery;
    QSqlQuery *query4 = new QSqlQuery;


};

#endif // STOCK_H
