#ifndef DEPOSIT_H
#define DEPOSIT_H

#include "account.h"

class Deposit : public Account
{
private:
    double percent;
public:
    explicit Deposit(double percent = 0, QString account = "", double balance = 0);
    double getPercent()
    {
        return this->percent;
    }
    void setPersent(double percent)
    {
        this->percent = percent;
    }
    ~Deposit()
    {

    }
};

#endif // DEPOSIT_H
