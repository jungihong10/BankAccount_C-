#ifndef CHECKING_H
#define CHECKING_H

#include "BankAccount.h"

class Checking : public BankAccount{
    public:
        Checking(int num=0,float bal=0,float min=1000,float chg=2) : BankAccount(num, bal), minimum(min), charge(chg) {}
        
        int withdraw(float amount) {
            if (this->bal < minimum) {
                if(this->bal < amount + charge) {
                    cout << "Cannot withdraw $" << amount + charge << " on account #" << this->acctnum << " because the balance is low." << endl;
                    return 0;
                } else {
                    this->bal -= (amount + charge);
                    return 1;
                }
            } else if (this->bal < amount) {
                cout << "Cannot withdraw $" << amount << " on account #" << this->acctnum << " because the balance is low." << endl;
                return 0;
            } else {
                this->bal -= amount;
                return 1;
            }
        }

        virtual void print() {
            cout << "Checking Account: " << this->acctnum << " Bankname:" << this->bank_name << "Credit:" << this->credit << "\n"
                 << "\tBalance: " << this->bal << "\n\tMinimum to Avoid Charges: " << this->minimum << "\n\tCharge per Check: " << this->charge << endl;
        }

    protected:
        //minimum account balance to keep(유지되야 하는 최소한의 잔고)
        float minimum; 
        // amount of money charged when balance is below minimum(minimum이 유지안되었을 때 발생하는 벌금)
        float charge;
};

#endif
