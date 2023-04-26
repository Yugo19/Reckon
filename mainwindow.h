#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "interface.h"
#include <QtSql/QSqlDatabase>
#include <QMessageBox>
#include <QSqlQuery>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();


private:
    Ui::MainWindow *ui;
    Interface *window;
    QSqlQuery *query = new QSqlQuery;
};
#endif // MAINWINDOW_H
