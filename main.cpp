#include <iostream>
#include <bank.hpp>

using namespace std;
using namespace bank;

typedef unsigned char uchar;
void actions(uchar&, Account);

int main(int, char**) {

    Customer *c = new Customer();
    uchar fp;

    c->initialize();
    cout << "Press Enter to continue..." << endl;
    getchar();

    if (getchar() == 0x0A){
    
        do
        {
            clcsc;
            cout << "Choose account to access: (Key Press)" <<endl;
            cout << "C Current\nS Savings\nI Summary\nQ Exit" <<endl;

            fp = getchar();

            switch(fp)
            {
                case 0x63:
                    options();
                    break;

                case 0x69:
                    c->customerInfo(); 
                    break;
                
                case 0x73:
                    options();
                    break;

                default: break;
            }

        }while(fp != 0x71);
    }
    
    delete(c);
}

void actions(uchar &key, Account acct)
{
    double amt;
    switch (cin.get())
    {
        case 0x62:
            cout << "Account Balance: " << getBalance(acct) <<endl;
            break;
        
        case 0x64:
            cout << "Enter Ammount > ";
            cin >> amt;
            acct.deposit(amt); 
            break;

        case 0x77:
            cout << "Enter Amount" ;
            cin >> amt;
            acct.withdraw(amt);
            break;

        case 0x74:
            acct.transactionHistory();
            break;

        case 0x69:
            acct.accountInfo();
            break;

        default: break;
    }
}