#include <iostream>
#include "bank.hpp"
#include "utils.hpp"


using namespace std;
using namespace bank;

int main(int, char**) {

    unique_ptr<Customer> customer(new Customer());
    signUp(customer.get());

    cout << "Press any key to continue..." << endl;
    auto choice = getchar();

    do
    {
        clearScreen;
        cout << "\nChoose account to access: (Key Press)" << endl;
        cout << "C Current\nS Savings\nI Summary\nQ Exit" << endl;

        choice = getchar();

        if (choice == 99){
            options();
            choice = getchar();
            actions(choice, customer->accounts.front());
        }
        else if (choice == 105)
            customer->customerInfo();

        else if (choice == 115){
            options();
            choice = getchar();
            actions(choice, customer->accounts.back());
        }

        continue;

    }while(choice != 'q');

    return 0;
}

