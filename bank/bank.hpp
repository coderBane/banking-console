#ifndef BANK_HPP
#define BANK_HPP

#include <list>
#include <string>
#include "utilities.hpp"
#include "nlohmann/json.hpp"

namespace bank{

    enum TransactionType { DEBIT, CREDIT, INTEREST, CHARGE };

    enum TransactionStatus { PENDING, COMPLETED, REJECTED };
    
    struct Transaction
    {
        time_t date;
        double amount;
        std::string note;
        TransactionType type;
        TransactionStatus status;

        Transaction(double, TransactionType, double&, std::string note = "", TransactionStatus = COMPLETED);
    };

    //Base class for Accounts
    class Account
    {
        private:
            time_t created;
            unsigned int accountNo;
            std::string fname, sname; 
        protected:
            double balance;
            std::list<Transaction> transactions;
        public:
            std::string fullname;
            friend double getBalance(Account);
            Account(std::string, std::string, double balance = 0.0);
            void withdraw(double amount);
            void deposit(double amount);
            void transactionHistory() const;
            std::string accountInfo() const;
    };

    double getBalance(Account account);
    
    // class bank
    // {
    // private:
    //     /* data */
    // public:
    //     bank(/* args */);
    //     ~bank();
    // };
    
    // bank::bank(/* args */)
    // {
    // }
    
    // bank::~bank()
    // {
    // }
    
}

#endif