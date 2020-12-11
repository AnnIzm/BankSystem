#include "menuwindow.h"
#include "ui_menuwindow.h"
#include "creditform.h"
#include "depositform.h"

MenuWindow::MenuWindow(QString login) :
    login(login),
    ui(new Ui::MenuWindow)
{
    ui->setupUi(this);
    ui->label->setText("Аккаунт: " + login);
    QList<Account> * accountList = new QList<Account>();
    File::openAccount(accountList, "account.txt");
    for (int i = 0; i < accountList->size(); i++) {
        if(accountList->operator[](i).getAccount() == login) {
            ui->label_2->setText("Сумма на счету: " + QString::number(accountList->operator[](i).getBalance()));
        }
    }

}

MenuWindow::~MenuWindow()
{
    delete ui;
}

void MenuWindow::on_exit_clicked()
{
    QApplication::exit(0);
}

void MenuWindow::on_add_clicked()
{
    double add = ui->lineEdit->text().toDouble();
    QList<Account> * accountList = new QList<Account>();
    File::openAccount(accountList, "account.txt");
    for (int i = 0; i < accountList->size(); i++) {
        if(accountList->operator[](i).getAccount() == login) {
            accountList->operator[](i).setBalance(accountList->operator[](i).getBalance() + add);
            ui->label_2->setText("Сумма на счету: " + QString::number(accountList->operator[](i).getBalance()));
        }
    }
    File::saveAccount(accountList, "account.txt");
    ui->lineEdit->setText("");
}

void MenuWindow::on_get_clicked()
{
    double get = ui->lineEdit->text().toDouble();
    QList<Account> * accountList = new QList<Account>();
    File::openAccount(accountList, "account.txt");
    for (int i = 0; i < accountList->size(); i++) {
        if(accountList->operator[](i).getAccount() == login) {
            accountList->operator[](i).setBalance(accountList->operator[](i).getBalance() - get);
            ui->label_2->setText("Сумма на счету: " + QString::number(accountList->operator[](i).getBalance()));
        }
    }
    File::saveAccount(accountList, "account.txt");
    ui->lineEdit->setText("");
}

void MenuWindow::on_credit_clicked()
{
    CreditForm *w = new CreditForm(login);
    w->show();
    this->close();
    delete this;
}

void MenuWindow::changed() {
    QList<Account> * accountList = new QList<Account>();
    File::openAccount(accountList, "account.txt");
    for (int i = 0; i < accountList->size(); i++) {
        if(accountList->operator[](i).getAccount() == login) {
            ui->label_2->setText("Сумма на счету: " + QString::number(accountList->operator[](i).getBalance()));
        }
    }
}

void MenuWindow::on_deposit_clicked()
{
    DepositForm *w = new DepositForm(login);
    w->show();
    this->close();
    delete this;
}
