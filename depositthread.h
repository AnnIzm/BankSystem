#ifndef DEPOSITTHREAD_H
#define DEPOSITTHREAD_H

#include "credit.h"
#include "file.h"
#include <QList>
#include <QThread>

class DepositThread : public QThread
{
public:
    DepositThread();
    void run()
    {
        QList<Deposit> *depositList = new QList<Deposit>();
        while(true)
        {
            File::openDeposit(depositList, "deposit.txt");
            for (int i = 0; i < depositList->size(); i++)
            {
                depositList->operator[](i).setBalance(depositList->operator[](i).getBalance() +
                        depositList->operator[](i).getBalance() * depositList->operator[](i).getPercent());
            }
            File::saveDeposit(depositList, "deposit.txt");
            depositList->clear();
            this->sleep(10);
        }
    }
};

#endif // DEPOSITTHREAD_H
