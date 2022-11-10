#include <iostream>
#include "bank.hpp"

using namespace std;
using json = nlohmann::json;

void bank::Customer::initialize(string firstname, string lastname, string dob)
{
    fname = firstname;
    sname = lastname;
    dob = dob;

    createAccount();

    userId = generateNo(23100000000001, 75720000000001);
    joined = time(nullptr);

    cout << "Your Account(s) have been registered."<<endl;
}

void bank::Customer::createAccount()
{
    if (accounts.size() < 2){
        accounts.push_back(CurrentAccount(fname, sname, 0.0));
        accounts.push_back(SavingsAccount(fname, sname, 0.0));
    }
    else
        cout << "Cannot create anymore accounts. Sorry!" <<endl;
}

void bank::Customer::customerInfo() const
{
    // json info;
    // info["Id"] = userId;
    // info["Person"] = {
    //     {"Name", fname + " " + sname},
    //     {"DoB", dob},
    // };
    // info["No. of Accounts"] = accounts.size();
    // info["Accounts"] = json::array(
    //     {"Current", accounts.front().accountInfo()},
    //     {"Savings", accounts.back().accountInfo()}
    // )};

    // info["Date Registered"] = ctime(&joined);

    // clcsc;
    // cout << info.dump(5);
}

// std::list<bank::Account> bank::Customer::getAccounts() { return accounts; }