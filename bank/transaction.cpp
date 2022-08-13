#include "bank.hpp"

using namespace std;

bank::Transaction::Transaction(double amount, TransactionType type, double& balance,
string note, TransactionStatus status)
{
    this->amount = amount;
    this->type = type;
    this->note = note;
    this->status = status;
    balance += (status & 1) ? amount : 0.0;
    date = time(nullptr);
}
