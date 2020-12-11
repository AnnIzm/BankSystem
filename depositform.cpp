#include "depositform.h"
#include "ui_depositform.h"
#include "menuwindow.h"

DepositForm::DepositForm(QString login) :
    login(login),
    ui(new Ui::DepositForm)
{
    ui->setupUi(this);
    ui->spinBox->setMinimum(1);
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Счёт"));
    ui->tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("Сумма"));
    ui->tableWidget->setHorizontalHeaderItem(2, new QTableWidgetItem("Процент"));
    QList<Deposit> * depositList = new QList<Deposit>();
    File::openDeposit(depositList, "deposit.txt");
    int i = 0;
    for (int j = 0; j < depositList->size(); j++) {
        if(depositList->operator[](j).getAccount() == login) {
            ui->tableWidget->insertRow(i);
            ui->tableWidget->setItem(i, 0, new QTableWidgetItem(depositList->operator[](j).getAccount()));
            ui->tableWidget->setItem(i, 1, new QTableWidgetItem(QString::number(depositList->operator[](j).getBalance())));
            ui->tableWidget->setItem(i, 2, new QTableWidgetItem(QString::number(depositList->operator[](j).getPercent())));
            i++;
        }
    }
    ui->spinBox->setMaximum(i + 1);
    ui->tableWidget->resizeColumnsToContents();
}

DepositForm::~DepositForm()
{
    delete ui;
}

void DepositForm::on_pay_clicked()
{
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(0);
    double balance = 0;
    int number = ui->spinBox->text().toInt();
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Счёт"));
    ui->tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("Сумма"));
    ui->tableWidget->setHorizontalHeaderItem(2, new QTableWidgetItem("Процент"));
    QList<Deposit> * depositList = new QList<Deposit>();
    File::openDeposit(depositList, "deposit.txt");
    int i = 0;
    for (int j = 0; j < depositList->size(); j++) {
        if(depositList->operator[](j).getAccount() == login) {
            if (i == number - 1) {
                balance = depositList->operator[](j).getBalance();
                depositList->removeAt(j);
                number = -1;
            } else {
                ui->tableWidget->insertRow(i);
                ui->tableWidget->setItem(i, 0, new QTableWidgetItem(depositList->operator[](j).getAccount()));
                ui->tableWidget->setItem(i, 1, new QTableWidgetItem(QString::number(depositList->operator[](j).getBalance())));
                ui->tableWidget->setItem(i, 2, new QTableWidgetItem(QString::number(depositList->operator[](j).getPercent())));
                i++;
            }
        }
    }
    ui->tableWidget->resizeColumnsToContents();
    File::saveDeposit(depositList, "deposit.txt");

    QList<Account> * accountList = new QList<Account>();
    File::openAccount(accountList, "account.txt");
    for (int i = 0; i < accountList->size(); i++) {
        if(accountList->operator[](i).getAccount() == login) {
            accountList->operator[](i).setBalance(accountList->operator[](i).getBalance() + balance);
        }
    }
    File::saveAccount(accountList, "account.txt");
}

void DepositForm::on_new_2_clicked()
{
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(0);
    double percent = double(qrand() % 50) / 100;
    double balance = ui->lineEdit->text().toDouble();
    Deposit deposit(percent, login, balance);
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Счёт"));
    ui->tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("Сумма"));
    ui->tableWidget->setHorizontalHeaderItem(2, new QTableWidgetItem("Процент"));
    QList<Deposit> * depositList = new QList<Deposit>();
    File::openDeposit(depositList, "deposit.txt");
    depositList->append(deposit);
    int i = 0;
    for (int j = 0; j < depositList->size(); j++) {
        if(depositList->operator[](j).getAccount() == login) {
            ui->tableWidget->insertRow(i);
            ui->tableWidget->setItem(i, 0, new QTableWidgetItem(depositList->operator[](j).getAccount()));
            ui->tableWidget->setItem(i, 1, new QTableWidgetItem(QString::number(depositList->operator[](j).getBalance())));
            ui->tableWidget->setItem(i, 2, new QTableWidgetItem(QString::number(depositList->operator[](j).getPercent())));
            i++;
        }
    }
    ui->tableWidget->resizeColumnsToContents();
    File::saveDeposit(depositList, "deposit.txt");
    ui->spinBox->setMaximum(i + 1);

    QList<Account> * accountList = new QList<Account>();
    File::openAccount(accountList, "account.txt");
    for (int i = 0; i < accountList->size(); i++) {
        if(accountList->operator[](i).getAccount() == login) {
            if (balance > accountList->operator[](i).getBalance()) {
                QMessageBox::critical(nullptr, "Новый депозит", "Недостаточно средств!");
                return;
            }
            accountList->operator[](i).setBalance(accountList->operator[](i).getBalance() - balance);
        }
    }
    File::saveAccount(accountList, "account.txt");
    ui->lineEdit->setText("");
}

void DepositForm::on_back_clicked()
{
    MenuWindow *w = new MenuWindow(login);
    w->show();
    this->close();
    delete this;
}
