#ifndef CFSELL_H
#define CFSELL_H

#include <QDialog>
#include "ui_sell.h"
#include "sell.h"

namespace Ui {
class Cfsell;
}

class Cfsell : public QDialog
{
    Q_OBJECT

public:
    explicit Cfsell(QWidget *parent = nullptr);
    ~Cfsell();

private slots:
    void on_lineEdit_2_textChanged(const QString &arg1);

    void on_pushButton_clicked();

private:
    Ui::Cfsell *ui;
    Ui_Sell *sui = new Ui_Sell;
};

#endif // CFSELL_H
