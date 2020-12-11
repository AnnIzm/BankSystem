#include "deposit.h"

Deposit::Deposit(double percent, QString account, double balance) : Account(account, balance), percent(percent)
{
}
