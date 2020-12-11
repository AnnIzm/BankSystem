#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <QString>

class Account
{
protected:
    QString account;
    double balance;
public:
    explicit Account(QString account = "", double balance = 0);
    double getBalance()
    {
        return this->balance;
    }
    void setBalance(double balance)
    {
        this->balance = balance;
    }
    QString getAccount()
    {
        return this->account;
    }
    void setAccount(QString account)
    {
        this->account = account;
    }
    ~Account()
    {

    }
};

#endif // ACCOUNT_H
