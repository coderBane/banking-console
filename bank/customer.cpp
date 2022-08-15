#include <iostream>
#include "bank.hpp"

using namespace std;
using json = nlohmann::json;

static random_device rd;
void bank::Customer::initialize()
{
    clcsc;
    cout << "Welcome to Bane Bank.\nLets get you set up!" <<endl;
    cout << "Please your Firstname: ";
    cin >> fname;
    cout << "Please your Surname: ";
    cin >> sname;
    cout << "Please your DoB (dd/mm/yyyy): ";
    cin >> dob;
    cout << "Please your Address: ";
    cin >> address;
    cout << "\n";
    createAccount();

    id = rd();
    joined = time(nullptr);

    cout << "Your Account(s) have been registered."<<endl;
}

void bank::Customer::createAccount()
{
    cout << "Choose accounts to create:" <<endl;
    cout << "C for current account\nS for Savings account" <<endl;
    switch (cin.get())
    {
    case 0x73:
        accounts.push_back(CurrentAccount(fname, sname, 0.0));
        break;
    case 0x63:
        accounts.push_back(SavingsAccount(fname, sname, 0.0));
        break;
    default:
        break;
    }
}

void bank::Customer::customerInfo() const
{
    json info;
    info["Id"] = id;
    info["Person"] = {
        {"Name", fname + " " + sname},
        {"DoB", dob},
        {"Address", address},
    };
    info["No. of Accounts"] = accounts.size();
    info["Accounts"] = {

    };

    info["Date Registered"] = ctime(&joined);

    clcsc;
    cout << info.dump(5);
}