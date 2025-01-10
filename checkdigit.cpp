#include "checkdigit.h"
#include <iostream>

int sigma(int argument)
{
    switch(argument)
    {
    case 0:
        return 1;
    case 1:
        return 5;
    case 2:
        return 7;
    case 3:
        return 6;
    case 4:
        return 2;
    case 5:
        return 8;
    case 6:
        return 3;
    case 7:
        return 0;
    case 8:
        return 9;
    case 9:
        return 4;
    }

    return int(); // this line will never be reached and this code doesn't matter
}

int sigma(int exponent, int argument)
{
    int prev_result = sigma(argument); // higher than any output of sigma(int)
    for(int i = 1; i < exponent; i++)
    {
        prev_result = sigma(prev_result); // use the previous result if this is not the first calculation
    }
    return prev_result; // the last result produced is the final result
}

int dihedral5(std::vector<int> elements)
{
    // The Cayley table of D5 represented with rotations 0-4 and reflections 5-9
    int D5[10][10] =
        {
            {0, 1, 2, 3, 4, 5, 6, 7, 8, 9},
            {1, 2, 3, 4, 0, 6, 7, 8, 9, 5},
            {2, 3, 4, 0, 1, 7, 8, 9, 5, 6},
            {3, 4, 0, 1, 2, 8, 9, 5, 6, 7},
            {4, 0, 1, 2, 3, 9, 5, 6, 7, 8},
            {5, 9, 8, 7, 6, 0, 4, 3, 2, 1},
            {6, 5, 9, 8, 7, 1, 0, 4, 3, 2},
            {7, 6, 5, 9, 8, 2, 1, 0, 4, 3},
            {8, 7, 6, 5, 9, 3, 2, 1, 0, 4},
            {9, 8, 7, 6, 5, 4, 3, 2, 1, 0}
        };

    // This is commented out because in J. Gallian they are using left to right order of multiplication for this representation....
    // Dn groups multiply right to left and are NOT Abelian/commutative
    // std::reverse(elements.begin(), elements.end());

    // Carry out the 'multiplication' using the cayley table 
    int outside = elements.at(0); // in algebraic notation this is the outermost factor in every line of evaluation
    for(int i = 0; i < elements.size() - 1; i++)
    {
        outside = D5[outside][elements.at(i+1)]; // evaluate the outermost multiplication
    }
    return outside; // the last value calculated is the result
}