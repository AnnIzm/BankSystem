#ifndef CREDITFORM_H
#define CREDITFORM_H

#include <QWidget>
#include "file.h"
#include "credit.h"
#include <QList>
#include <QMessageBox>

namespace Ui
{
class CreditForm;
}

class CreditForm : public QWidget
{
    Q_OBJECT

public:
    explicit CreditForm(QString login = nullptr);
    ~CreditForm();

private slots:
    void on_back_clicked();

    void on_new_2_clicked();

    void on_pay_clicked();

private:
    Ui::CreditForm *ui;
    QString login;
};

#endif // CREDITFORM_H
