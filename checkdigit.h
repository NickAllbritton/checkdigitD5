#ifndef CHECKDIGIT_H
#define CHECKDIGIT_H

#include <vector>
#include <algorithm>

// sigmaStr = "01589427"

// Calculate the first order sigma functional
int sigma(int argument);

// Calculate some power of the sigma functional
int sigma(int exponent, int argument);

// Calculate the ordered multiplication of 11 elements of D5 represented as digits 0-9
int dihedral5(std::vector<int> elements);

#endif