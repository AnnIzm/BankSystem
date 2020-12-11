#ifndef FILE_H
#define FILE_H

#include "credit.h"
#include <QList>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class File {
public:
    static void openAccount(QList<Account> *accountList, string file)
    {
        ifstream in(file);
        while (!in.eof())
        {
            string account;
            double balance;
            getline(in, account);
            if (account == "") break;
            in >> balance;
            in.get();
            Account newAccount(QString::fromStdString(account), balance);
            accountList->append(newAccount);
        }
        in.close();
    }

    static void saveAccount(QList<Account> *accountList, string file)
    {
        ofstream on(file);
        for (int i = 0; i < accountList->size(); i++)
        {
            on << accountList->operator[](i).getAccount().toStdString() << endl;
            on << accountList->operator[](i).getBalance() << endl;
        }
        on.close();
    }

    static void openDeposit(QList<Deposit> *depositList, string file)
    {
        ifstream in(file);
        while (!in.eof())
        {
            string account;
            double balance, percent;
            getline(in, account);
            if (account == "") break;
            in >> balance >> percent;
            in.get();
            Deposit newDeposit(percent, QString::fromStdString(account), balance);
            depositList->append(newDeposit);
        }
        in.close();
    }

    static void saveDeposit(QList<Deposit> *depositList, string file)
    {
        ofstream on(file);
        for (int i = 0; i < depositList->size(); i++)
        {
            on << depositList->operator[](i).getAccount().toStdString() << endl;
            on << depositList->operator[](i).getBalance() << " " << depositList->operator[](i).getPercent() << endl;
        }
        on.close();
    }

    static void openCredit(QList<Credit> *creditList, string file)
    {
        ifstream in(file);
        while (!in.eof())
        {
            string account;
            double balance, percent;
            getline(in, account);
            if (account == "") break;
            in >> balance >> percent;
            in.get();
            Credit newCredit(percent, QString::fromStdString(account), balance);
            creditList->append(newCredit);
        }
        in.close();
    }

    static void saveCredit(QList<Credit> *creditList, string file)
    {
        ofstream on(file);
        for (int i = 0; i < creditList->size(); i++)
        {
            on << creditList->operator[](i).getAccount().toStdString() << endl;
            on << creditList->operator[](i).getBalance() << " " << creditList->operator[](i).getPercent() << endl;
        }
        on.close();
    }
};

#endif // FILE_H
