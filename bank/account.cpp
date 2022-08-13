#include "bank.hpp"
#include <iostream>
#include <exception>

using namespace std;
using json = nlohmann::json;

bank::Account::Account(string fname, string sname, double balance)
{
    this->fname = fname;
    this->sname = sname;
    this->balance = balance;
    fullname = fname + " " + sname;
    accountNo = generateNo(31000000, 37000001);
    created = time(nullptr);
}

void bank::Account::deposit(double amount)
{
    (amount <= 0) ? throw range_error("Deposit amount must be greater than zero!") :
        transactions.push_front(Transaction(amount, CREDIT, balance));
}

void bank::Account::withdraw(double amount)
{
    transactions.push_front(Transaction(-amount, DEBIT,  balance));
}

string bank::Account::accountInfo() const
{
    json info ={
        {"Account Holder", fullname},
        {"Account no.", accountNo},
        {"Account Balance", balance},
        {"No. of Transactions", transactions.size()},
        {"Active Since", ctime(&created)},
    };

    return info.dump(5);
}

void bank::Account::transactionHistory() const
{
    cout << left;
    cout << "Date" << "\t" << "Amount" << "\t" << "Type" << "\t" << "Status" << "\t" << "Remarks" <<endl;
    for (const auto& prop : transactions)
    {
        cout << put_time(localtime(&prop.date),"%F %T %Z") << "\t" << prop.amount << "\t" << prop.type 
                << "\t" << prop.status << "\t" << prop.note <<endl;
    }
}

double bank::getBalance(bank::Account account) { return account.balance; }