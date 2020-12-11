#ifndef DEPOSITFORM_H
#define DEPOSITFORM_H

#include <QWidget>
#include "file.h"
#include "credit.h"
#include <QList>
#include <QMessageBox>

namespace Ui
{
class DepositForm;
}

class DepositForm : public QWidget
{
    Q_OBJECT

public:
    explicit DepositForm(QString login = nullptr);
    ~DepositForm();

private slots:
    void on_pay_clicked();

    void on_new_2_clicked();

    void on_back_clicked();

private:
    Ui::DepositForm *ui;
    QString login;
};

#endif // DEPOSITFORM_H
