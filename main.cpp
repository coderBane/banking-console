#include <iostream>
#include <bank.hpp>

// #define getid(x) ((x).id)
using namespace bank;

int main(int, char**) {

    SavingsAccount acct("John", "Maddy", 200);

    acct.withdraw(250);
    acct.deposit(1000);
    acct.transactionHistory();
    acct.deposit(-1);
    
    std::cout << getBalance(acct);

}