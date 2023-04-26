#ifndef REGISTRY_H
#define REGISTRY_H

#include <QDialog>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "server.h"

namespace Ui {
class registry;
}

class registry : public QDialog
{
    Q_OBJECT

public:
    explicit registry(QWidget *parent = nullptr);
    ~registry();

private slots:
    void on_tableView_doubleClicked(const QModelIndex &index);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();
    void reload();

private:
    Ui::registry *ui;
    Server *db = new Server;
    QSqlQueryModel *model0 = new QSqlQueryModel;
};

#endif // REGISTRY_H
