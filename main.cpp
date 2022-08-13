#include <iostream>
#include <bank.hpp>

// #define getid(x) ((x).id)
using namespace bank;

struct s1{
    int id;
}a;

int main(int, char**) {

    Account acct("John", "Koln");

    std::cout << acct.accountInfo() <<std::endl;

    acct.deposit(3000);
    //acct.withdraw(200);
    //acct.withdraw(20.16);
    //acct.deposit(450);
    //acct.accountInfo();

    acct.transactionHistory();
    
    std::cout << getBalance(acct);
}