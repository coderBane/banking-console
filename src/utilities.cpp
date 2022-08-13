#include "utilities.hpp"

std::random_device rd;

int generateNo(int start, int lim)
{
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> uid(start,lim);
    return uid(gen);
}
