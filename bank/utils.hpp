#ifndef BANK_UTILS_HPP
#define BANK_UTILS_HPP

#include <cstdio>
#include <memory>
#include "bank.hpp"

#define clearScreen printf("\e[1;1H\e[2J")

void signUp(bank::Customer *customer);

void actions(int fp, bank::Account& account);

void options();

#endif