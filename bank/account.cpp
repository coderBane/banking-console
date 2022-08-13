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
    cout.fill(' ');
    cout <<setw(24) << left << "Date" << "| " << internal << setw(15) << "Amount" << " | "<< setw(10) << "Type" << " | " 
            << setw(10) << "Status" << " | "  << "Remarks" <<endl;
    cout << string(88, '-') << "\n";
    for (const auto& prop : transactions)
    {
        cout.precision(2);
        cout << put_time(localtime(&prop.date),"%F %T %Z") << " | "<< setw(15) << right << fixed << prop.amount << " | " 
                 << setw(10) << typStr[prop.type] << " | " << setw(10) << staStr[prop.status] << " | " << prop.note <<endl;
    }
}

void bank::CurrentAccount::withdraw(double amount)
{
    if (amount > balance){
        cout << "Account gone into overdraft." <<endl;
        transactions.push_front(Transaction(-charge, CHARGE, balance, "overdraft charges"));
    }
    Account::withdraw(amount);
}

int bank::SavingsAccount::count = 0;
void bank::SavingsAccount::withdraw(double amount)
{
    if (amount > balance){
        transactions.push_front(Transaction(-amount, DEBIT, balance, "Transaction denied", REJECTED));
        cerr << "Insufficient funds." <<endl;
    }
    else{
        Account::withdraw(amount);
        count++;

        if (count > 3)
            cout << "Exceeded limit." <<endl;
            transactions.push_front(Transaction(-charge, CHARGE, balance, "limit charges"));
    }
}

double bank::getBalance(bank::Account account) { return account.balance; }