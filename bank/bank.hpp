#ifndef BANK_HPP
#define BANK_HPP

#include <list>
#include <string>
#include <iomanip>
#include "utilities.hpp"
#include "nlohmann/json.hpp"


namespace bank{

    enum TransactionType { DEBIT, CREDIT, INTEREST, CHARGE };

    enum TransactionStatus { PENDING, COMPLETED, REJECTED };

    const char* const typStr[] = {
        [DEBIT] = "DEBIT",
        [CREDIT] = "CREDIT",
        [INTEREST] = "INTEREST",
        [CHARGE] = "CHARGE",
    };

    const char* const staStr[] = {
        [PENDING] = "PENDING",
        [COMPLETED] = "COMPLETED",
        [REJECTED] = "REJECTED",
    };

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
            void deposit(double amount);
            virtual void withdraw(double amount);
            void transactionHistory() const;
            std::string accountInfo() const;
    };


    class CurrentAccount : public Account
    {
        private:
            const double charge = 10.0;
        public:
            CurrentAccount(std::string fname, std::string sname, double balance) : Account(fname, sname, balance){};
            void withdraw(double amount);
    };


    class SavingsAccount : public Account
    {
        private:
            const double charge = 2.0;
            const double rate = 0.012;
            static int count;
        public:
            SavingsAccount(std::string fname, std::string sname, double balance) : Account(fname, sname, balance){};
            void withdraw(double amount);
            void applyInterest();
    };


    class Customer
    {
        private:
            std::string fname, sname, dob, address;
            unsigned long id;
            time_t joined;
        protected:
            std::list<Account> accounts;
        public:
            void initialize();
            void createAccount();
            void customerInfo() const;
            std::list<Account> getAccounts();
    };
    
    
    double getBalance(Account account);
}

#endif