#include <iostream>
#include "utils.hpp"

using namespace std;

void signUp(bank::Customer *customer)
{
    clearScreen;
    unique_ptr<string> f(new string()), s(new string()), d(new string());
    cout << "Welcome to Bane's Bank.\nLets get you set up!" << endl;
    cout << "Please your Firstname: ";
    cin >> *f;
    cout << "Please your Surname: ";
    cin >> *s;
    cout << "Please your DoB (dd/mm/yyyy): ";
    cin >> *d;
    cout << endl;

    customer->initialize(*f,*s,*d);
}

void actions(int fp, bank::Account& account)
{
    switch (fp)
    {
        case 'b': cout << "Account Balance" << getBalance(account) << endl; 
            break;
        case 'i': account.accountInfo();
            break;
        case 't': account.transactionHistory();
            break;
        case 'd':{
            double amt;
            cin >> amt;
            account.deposit(amt);
        }break;

        case 'w':{
            double amt;
            cin >> amt;
            account.withdraw(amt);
        }break;

        default: break;
    }
}

void options()
{
    const char *opt[] = { 
        "I Account Information", "B Account Balance", "D Make A Deposit",
        "W Make a Withdrawal", "T Account Transactions", "Any other key to go back." 
    };
    
    clearScreen;
    cout << "Perform Action: (Key Press)" << endl;
    for (const auto &i : opt)
        cout << i <<std::endl;
}

