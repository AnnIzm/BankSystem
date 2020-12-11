#ifndef CREDIT_H
#define CREDIT_H

#include "deposit.h"

class Credit : public Deposit
{
public:
    explicit Credit(double percent = 0, QString account = "", double balance = 0);
    ~Credit(){}
};

#endif // CREDIT_H
