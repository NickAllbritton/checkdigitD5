#include "checkdigit.h"

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
    int prev_result = 10;
    for(int i = 0; i < exponent; i++)
    {
        if(prev_result < 10) prev_result = sigma(prev_result); // use the previous result if this is not the first calculation
        else prev_result = sigma(argument); // otherwise, use the inside argument
    }
    return prev_result; // the last result produced is the final result
}