#ifndef INTERFACE_H
#define INTERFACE_H

#include <QDialog>
#include "registry.h"
#include "sell.h"
#include "stock.h"

namespace Ui {
class Interface;
}

class Interface : public QDialog
{
    Q_OBJECT

public:
    explicit Interface(QWidget *parent = nullptr);
    ~Interface();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::Interface *ui;
    registry *rw;
    Sell *sw;
    Stock *skw;


};

#endif // INTERFACE_H
