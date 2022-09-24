#include "utilities.hpp"
#include <iostream>

std::random_device rd;

int generateNo(int start, int lim)
{
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> uid(start,lim);
    return uid(gen);
}

void options()
{
    const char *opt[] = { "I Account Information", "B Account Balance", "D Make A Deposit",
                "W Make a Withdrawal", "T Account Transactions", "Any other key to go back." };

    clcsc;
    std::cout << "Perform Action: (Key Press)" <<std::endl;
    for (const auto &i : opt)
        std::cout << i <<std::endl;
}
