#ifndef IMPRIMER_H
#define IMPRIMER_H

#include <QDialog>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "server.h"


namespace Ui {
class imprimer;
}

class imprimer : public QDialog
{
    Q_OBJECT

public:
    explicit imprimer(QWidget *parent = nullptr);
    ~imprimer();
    const char *request = "select Nom, Quantite, Prix from tempells";

private slots:
    void on_lineEdit_textChanged(const QString &arg1);

    void on_pushButton_clicked();

private:
    Ui::imprimer *ui;
    Server *db = new Server;
    QSqlQueryModel model;

};

#endif // IMPRIMER_H
