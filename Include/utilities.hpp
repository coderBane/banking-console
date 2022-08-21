#ifndef UTILITIES_HPP
#define UTILITIES_HPP

#include <stdio.h>
#include <random>

/**
 * @brief clear console
 * 
 */
#define clcsc printf("\e[1;1H\e[2J")

#define enroll(x) (x->initialize())

int generateNo(int, int);

#endif