#ifndef CREDITTHREAD_H
#define CREDITTHREAD_H

#include <QThread>
#include "credit.h"
#include "file.h"

class CreditThread : public QThread
{
public:
    CreditThread();
    void run() override
    {
        QList<Credit> *creditList = new QList<Credit>();
        while(true)
        {
            File::openCredit(creditList, "credit.txt");
            for (int i = 0; i < creditList->size(); i++)
            {
                creditList->operator[](i).setBalance(creditList->operator[](i).getBalance() +
                        creditList->operator[](i).getBalance() * creditList->operator[](i).getPercent());
            }
            File::saveCredit(creditList, "credit.txt");
            creditList->clear();
            this->sleep(10);
        }
    }
};

#endif // CREDITTHREAD_H
