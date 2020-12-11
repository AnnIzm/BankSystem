#include "authorisewindow.h"
#include "ui_authorisewindow.h"

AuthoriseWindow::AuthoriseWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AuthoriseWindow)
{
    ui->setupUi(this);
}

AuthoriseWindow::~AuthoriseWindow()
{
    delete ui;
}


void AuthoriseWindow::on_authorization_clicked()
{
    QString account = ui->lineEdit->text();
    if(account.size() < 1) {
        QMessageBox::critical(nullptr, "Add account", "Write the account number!");
    } else {
        QList<Account> * accountList = new QList<Account>();
        File::openAccount(accountList, "account.txt");
        for (int i = 0; i < accountList->size(); i++) {
            if(accountList->operator[](i).getAccount() == account) {
                MenuWindow *w = new MenuWindow(account);
                w->show();
                this->close();
                delete this;
                return;
            }
        }
        Account newAccount(account, 0);
        accountList->append(newAccount);
        File::saveAccount(accountList, "account.txt");
        MenuWindow *w = new MenuWindow(account);
        w->show();
        this->close();
        delete this;
    }
}

void AuthoriseWindow::on_exit_clicked()
{
    QApplication::exit(0);
}
