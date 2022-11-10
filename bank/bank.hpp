#ifndef BANK_HPP
#define BANK_HPP

#include <list>
#include <string>
#include <random>
#include <iomanip>
#include "nlohmann/json.hpp"

static std::random_device rd;

constexpr auto generateNo = [](size_t start, size_t limit)
{
    std::mt19937_64 gen(rd());
    std::uniform_int_distribution<std::mt19937_64::result_type> uid(start, limit);
    return uid(gen);
};


namespace bank{

    enum TransactionType { DEBIT, CREDIT, INTEREST, CHARGE };

    enum TransactionStatus { PENDING, COMPLETED, REJECTED };

    // Transaction type translations
    const char* const typeTrans[] = {
        [DEBIT] = "DEBIT",
        [CREDIT] = "CREDIT",
        [INTEREST] = "INTEREST",
        [CHARGE] = "CHARGE",
    };

    // Transaction status translations
    const char* const statusTrans[] = {
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

        Transaction(double amount, TransactionType type, double& accountBalance, std::string note = "", TransactionStatus status = COMPLETED);
        ~Transaction();
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
            friend double getBalance(Account account);
            Account(std::string fname, std::string sname, double balance = 0.0);
            void deposit(double amount);
            virtual void withdraw(double amount);
            void transactionHistory() const;
            const std::string accountInfo() const;

            ~Account();
    };


    class CurrentAccount : public Account
    {
        private:
            const double charge = 10.0;
            const double overdraft_max = 100.0;
        public:
            CurrentAccount(std::string fname, std::string sname, double balance) : Account(fname, sname, balance){};
            void withdraw(double amount) override;
    };


    class SavingsAccount : public Account
    {
        private:
            const double charge = 2.0;
            const double rate = 0.012;
            static int count;
        public:
            SavingsAccount(std::string fname, std::string sname, double balance) : Account(fname, sname, balance){};
            void withdraw(double amount) override;;
            void applyInterest();
    };


    class Customer
    {
        private:
            std::string fname, sname, dob;
            size_t userId;
            time_t joined;
        public:
            std::list<Account> accounts;
            void createAccount();
            void customerInfo() const;
            void initialize(std::string firstname, std::string surname, std::string dob);
    };
    
    
    double getBalance(Account account);
}

#endif