#ifndef BANKSYSTEM_H
#define BANKSYSTEM_H

#include "BankAccount.h"
#include <cstring>
#include <vector>


class BankSystem {
    public:
        void addAccount(BankAccount* account) {
            accounts.push_back(account);
        }

        void applyInterest() {
            for (BankAccount* account : accounts) {
                InterestChecking* interestAccount = dynamic_cast<InterestChecking*>(account);
                if (interestAccount != nullptr) {
                    interestAccount->interest();
                }
            }
        }
        void transaction(BankAccount* from, BankAccount* to, float amount) {
            float transaction_fee = from->getBankname().compare(to->getBankname()) == 0 ? 0 : 5;
            if (from->getBalance() >= amount + transaction_fee) {
                if (from->withdraw(amount + transaction_fee) == 1) {
                    to->deposit(amount);
                } else {
                    from->deposit(transaction_fee); // Return transaction fee if the transaction failed
                }
            } else {
                cout << "Cannot withdraw $" << amount + transaction_fee << " on account #" << from->getAcctnum() << " because the balance is low." << endl;
            }
        }



        void deposit(BankAccount* b, float amount) {
            b->deposit(amount);

        }

        void withdraw(BankAccount* b, float amount) {
            b->withdraw(amount);

        }

        void loan(BankAccount* b, float amount) {
            float bal = b->getBalance();
            if (bal < 1000) {
                cout << "The amount cannot be loaned" << endl;
            } else if (bal >= 1000 && bal < 2000) {
                if (amount < 100 || amount > 500) {
                    cout << "The amount cannot be loaned" << endl;
                } else {
                    b->deposit(amount * 0.9);
                }
            } else {
                if (amount < 100 || amount > 1000) {
                    cout << "The amount cannot be loaned" << endl;
                } else {
                    b->deposit(amount * 0.95);
                }
            }
        }
    private:
        std::vector<BankAccount*> accounts;

};

#endif
