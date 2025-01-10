#include <iostream>
#include <string>
#include <vector>

enum class FormError
{
    NoError,
    NoInputString,
    TooManyArgs,
    InvalidCharacters,
    InputLengthError
};

// Make sure the characters in the input string are from 0123456789ADGKLNSUYZ
bool validCharacters(std::string input)
{
    // TODO: This is the ugliest code I've ever written. Find a more elegant solution?

    // Check each character in the string
    for(auto c : input)
    {
        switch(c)
        {
        case '0':
            break;
        case '1':
            break;
        case '2':
            break;
        case '3':
            break;
        case '4':
            break;
        case '5':
            break;
        case '6':
            break;
        case '7':
            break;
        case '8':
            break;
        case '9':
            break;
        case 'A':
            break;
        case 'D':
            break;
        case 'G':
            break;
        case 'K':
            break;
        case 'L':
            break;
        case 'N':
            break;
        case 'S':
            break;
        case 'U':
            break;
        case 'Y':
            break;
        case 'Z':
            break;
        // If it does not match any of these characters, then it is an invalid character. 
        default:
            return false;
        }
    }
    // If an invalid character has not been encountered, then all the characters should be valid
    return true;
}

FormError evaluateInput(std::vector<std::string> inputArgs)
{
    if(inputArgs.size() == 1) return FormError::NoInputString;
    else if(inputArgs.size() > 2) return FormError::TooManyArgs;
    else if(inputArgs.at(1).length() != 11) return FormError::InputLengthError;
    else if(!validCharacters(inputArgs.at(1))) return FormError::InvalidCharacters;
    else
    {
        return FormError::NoError;
    }
}

int main(int argc, char* argv[])
{
    // Steps of program
    // Step 1: Evaluate the array of arguments for the correct number
    // Step 2: Evaluate the input string if present for correct length and characters 0123456789ADGKLNSUYZ
    // Step 3: Apply check digit scheme to print VALID or INVALID

    /******************** Convert c-strings to c++ string *********************/
    std::vector<std::string> inputs;

    for(int i = 0; i < argc; i++)
    {
        std::string str(argv[i]);
        inputs.push_back(str);
    }
    /**************************************************************************/

    /********************** Evaluate the form of input ************************/
    switch(evaluateInput(inputs))
    {
    case FormError::NoError:
        break;
    case FormError::NoInputString:
        std::cout << "No input string was given to check." << std::endl;
        std::cout << "Form: checkdigitD5 AG8536827U7" << std::endl;
        return -1;
    case FormError::TooManyArgs:
        std::cout << "Too many arguments given. Stopping." << std::endl;
        std::cout << "Form: checkdigitD5 AG8536827U7" << std::endl;
        return -1;
    case FormError::InvalidCharacters:
        std::cout << "The given input string has invalid characters. Please check your input and try again." << std::endl;
        return -1;
    case FormError::InputLengthError:
        std::cout << "The given input string is not 11 characters long. INVALID." << std::endl;
        return -1;
    }
    /**************************************************************************/

    std::cout << "No errors detected!" << std::endl;

    return 0;
}