#include "creditform.h"
#include "menuwindow.h"
#include "ui_creditform.h"

CreditForm::CreditForm(QString login) :
    login(login),
    ui(new Ui::CreditForm)
{
    ui->setupUi(this);
    ui->spinBox->setMinimum(1);
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Счёт"));
    ui->tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("Сумма"));
    ui->tableWidget->setHorizontalHeaderItem(2, new QTableWidgetItem("Процент"));
    QList<Credit> * creditList = new QList<Credit>();
    File::openCredit(creditList, "credit.txt");
    int i = 0;
    for (int j = 0; j < creditList->size(); j++) {
        if(creditList->operator[](j).getAccount() == login) {
            ui->tableWidget->insertRow(i);
            ui->tableWidget->setItem(i, 0, new QTableWidgetItem(creditList->operator[](j).getAccount()));
            ui->tableWidget->setItem(i, 1, new QTableWidgetItem(QString::number(creditList->operator[](j).getBalance())));
            ui->tableWidget->setItem(i, 2, new QTableWidgetItem(QString::number(creditList->operator[](j).getPercent())));
            i++;
        }
    }
    ui->spinBox->setMaximum(i + 1);
    ui->tableWidget->resizeColumnsToContents();
}

CreditForm::~CreditForm()
{
    delete ui;
}

void CreditForm::on_back_clicked()
{
    this->close();
    delete this;
    MenuWindow *w = new MenuWindow(login);
    w->show();
}

void CreditForm::on_new_2_clicked()
{
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(0);
    double percent = double(qrand() % 100) / 100;
    double balance = ui->lineEdit->text().toDouble();
    Credit credit(percent, login, balance);
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Счёт"));
    ui->tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("Сумма"));
    ui->tableWidget->setHorizontalHeaderItem(2, new QTableWidgetItem("Процент"));
    QList<Credit> * creditList = new QList<Credit>();
    File::openCredit(creditList, "credit.txt");
    creditList->append(credit);
    int i = 0;
    for (int j = 0; j < creditList->size(); j++) {
        if(creditList->operator[](j).getAccount() == login) {
            ui->tableWidget->insertRow(i);
            ui->tableWidget->setItem(i, 0, new QTableWidgetItem(creditList->operator[](j).getAccount()));
            ui->tableWidget->setItem(i, 1, new QTableWidgetItem(QString::number(creditList->operator[](j).getBalance())));
            ui->tableWidget->setItem(i, 2, new QTableWidgetItem(QString::number(creditList->operator[](j).getPercent())));
            i++;
        }
    }
    ui->tableWidget->resizeColumnsToContents();
    File::saveCredit(creditList, "credit.txt");
    ui->spinBox->setMaximum(i + 1);

    QList<Account> * accountList = new QList<Account>();
    File::openAccount(accountList, "account.txt");
    for (int i = 0; i < accountList->size(); i++) {
        if(accountList->operator[](i).getAccount() == login) {
            accountList->operator[](i).setBalance(accountList->operator[](i).getBalance() + balance);
        }
    }
    File::saveAccount(accountList, "account.txt");
    ui->lineEdit->setText("");
}

void CreditForm::on_pay_clicked()
{
    double balance = 0;
    int number = ui->spinBox->text().toInt();
    QList<Credit> * creditList = new QList<Credit>();
    File::openCredit(creditList, "credit.txt");
    int i = 0;
    for (int j = 0; j < creditList->size(); j++) {
        if(creditList->operator[](j).getAccount() == login) {
            if (i == number - 1) {
                balance = creditList->operator[](j).getBalance();
            }
            i++;
        }
    }
    QList<Account> * accountList = new QList<Account>();
    File::openAccount(accountList, "account.txt");
    for (int i = 0; i < accountList->size(); i++) {
        if(accountList->operator[](i).getAccount() == login) {
            if (balance > accountList->operator[](i).getBalance()) {
                QMessageBox::critical(nullptr, "Оплата кредита", "Недостаточно средств!");
                return;
            } else {
                accountList->operator[](i).setBalance(accountList->operator[](i).getBalance() - balance);
            }
        }
    }
    File::saveAccount(accountList, "account.txt");
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Счёт"));
    ui->tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("Сумма"));
    ui->tableWidget->setHorizontalHeaderItem(2, new QTableWidgetItem("Процент"));
    i = 0;
    for (int j = 0; j < creditList->size(); j++) {
        if(creditList->operator[](j).getAccount() == login) {
            if (i == number - 1) {
                creditList->removeAt(j);
                number = -1;
            }
            i++;
        }
    }
    i = 0;
        for (int j = 0; j < creditList->size(); j++) {
            if(creditList->operator[](j).getAccount() == login) {
                ui->tableWidget->insertRow(i);
                ui->tableWidget->setItem(i, 0, new QTableWidgetItem(creditList->operator[](j).getAccount()));
                ui->tableWidget->setItem(i, 1, new QTableWidgetItem(QString::number(creditList->operator[](j).getBalance())));
                ui->tableWidget->setItem(i, 2, new QTableWidgetItem(QString::number(creditList->operator[](j).getPercent())));
                i++;
            }
        }
    ui->tableWidget->resizeColumnsToContents();
    File::saveCredit(creditList, "credit.txt");
}
