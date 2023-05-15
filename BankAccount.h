#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include <string>
#include <cstdlib>
#include <iostream>
using namespace std;

class BankAccount{
    public:
        BankAccount(int num,float bal) : acctnum(num), bal(bal) {
            int randBank = rand() % 3;
            switch (randBank) {
                case 0:
                    bank_name = "하나";
                    break;
                case 1:
                    bank_name = "우리";
                    break;
                case 2:
                    bank_name = "신한";
                    break;
            }
            updateCredit();

        }
        

        void deposit(float amount) {
            bal += amount;
            updateCredit();
        }

        void loan(float amount) {
            if (credit == 1) {
                cout << "The amount cannot be loaned" << endl;
            } else if (credit == 2) {
                if (amount >= 100 && amount <= 500) {
                    bal += amount * 0.9; // 대출 수수료 10%
                } else {
                    cout << "The amount cannot be loaned" << endl;
                }
            } else if (credit == 3) {
                if (amount >= 100 && amount <= 1000) {
                    bal += amount * 0.95; // 대출 수수료 5%
                } else {
                    cout << "The amount cannot be loaned" << endl;
                }
            }
            updateCredit();
        }

        virtual int withdraw(float amount) {
            if (bal <= amount) {
                cout << "Cannot withdraw $" << amount << " on account #" << acctnum << " because the balance is low." << endl;
                return 0;
            } else {
                bal -= amount;
                return 1;
            }
        }

        int getAcctnum() {
            return acctnum;
        }

        float getBalance() {
            return bal;
        }

        int getcredit() {
            return credit;
        }

        string getBankname() {
            return bank_name;
        }

        virtual void print() = 0;

    protected:
        int acctnum; // account number(계좌번호)
        float bal; //current balance of account(현재 잔고)
        string bank_name;
        int credit;

    private:
        void updateCredit() {
            if (bal < 1000)
                credit = 1;
            else if (bal < 2000)
                credit = 2;
            else
                credit = 3;
        }
};

#endif
