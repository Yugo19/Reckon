#ifndef SELL_H
#define SELL_H

#include <QDialog>
#include "server.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QPrinter>
#include <QPrintDialog>
#include "imprimer.h"


namespace Ui {
class Sell;
}

class Sell : public QDialog
{
    Q_OBJECT

public:
    explicit Sell(QWidget *parent = nullptr);
    ~Sell();

private slots:
    void on_pushButton_clicked();

    void on_tableView_doubleClicked(const QModelIndex &index);

    void on_tableView_activated(const QModelIndex &index);

    void on_lineEdit_9_textChanged(const QString &arg1);

    void on_lineEdit_4_textChanged(const QString &arg1);

    void on_lineEdit_6_textChanged(const QString &arg1);

    void on_lineEdit_5_textChanged(const QString &arg1);

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_lineEdit_13_textChanged(const QString &arg1);

    void on_checkBox_stateChanged(int arg1);
    void randG();
    void reload();
    void randG1();

    void on_lineEdit_10_selectionChanged();

    void on_lineEdit_15_selectionChanged();

    void on_lineEdit_17_selectionChanged();

    void on_lineEdit_20_selectionChanged();

    void on_lineEdit_23_textChanged(const QString &arg1);

    void on_lineEdit_26_textChanged(const QString &arg1);

    void on_lineEdit_29_selectionChanged();

    void on_lineEdit_33_selectionChanged();

    void on_lineEdit_23_selectionChanged();

    void on_lineEdit_26_selectionChanged();

    void on_lineEdit_34_selectionChanged();

    void on_lineEdit_35_selectionChanged();

    void on_lineEdit_36_selectionChanged();

    void on_lineEdit_37_selectionChanged();

    void on_lineEdit_38_selectionChanged();

    void on_lineEdit_39_selectionChanged();

    void on_lineEdit_40_selectionChanged();

    void on_lineEdit_41_selectionChanged();

    void on_lineEdit_5_cursorPositionChanged(int arg1, int arg2);

private:
    Ui::Sell *ui;
    imprimer *iw;
    Server *db = new Server;
    QSqlQuery *query =new QSqlQuery;
    QSqlQueryModel *model1 = new QSqlQueryModel;
    QSqlQuery *qryD = new QSqlQuery;
    QSqlQuery *qryI = new QSqlQuery;
    QSqlQueryModel *model0 = new QSqlQueryModel;
    QSqlQueryModel *model2 = new QSqlQueryModel;
    QString text;


};

#endif // SELL_H
