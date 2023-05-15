#ifndef SAVINGS_H
#define SAVINGS_H

#include "BankAccount.h"

class Savings : public BankAccount {
    public:
        Savings(int num=0,float bal=0,float rate=3.5) : BankAccount(num, bal), intrate(rate) {}

        void interest() {
            bal += bal * (intrate / 100.0 / 12.0);
        }

        int withdraw(float amount) {
            if (bal <= amount) {
                cout << "Cannot withdraw $" << amount << " on account #" << acctnum << " because the balance is low." << endl;
                return 0;
            } else {
                bal -= amount;
                return 1;
            }
        }

        virtual void print() {
            cout << "\nSavings Account: " << acctnum << " Bankname:" << bank_name << "Credit:" << credit << "\n"
                 << "\tBalance: " << bal << "\n\tInterest: " << intrate << "%\n"<<endl;
        }

    protected:
        float intrate; //interest rate(이자율)
};

#endif
