#ifndef UTILITIES_HPP
#define UTILITIES_HPP

#include <stdio.h>
#include <random>

/**
 * @brief clear console
 * 
 */
#define clcsc printf("\e[1;1H\e[2J")

int generateNo(int, int);

void options();

#endif