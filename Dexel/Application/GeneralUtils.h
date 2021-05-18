#pragma once
#include <iostream>
char converToLower(char symbol)
{
    if (symbol <= 'Z' && symbol >= 'A')
    {
        return symbol - ('A' - 'a');
    }
    else
    {
        return symbol;
    }
}
std::string lowerred(std::string stringToLower)
{
    for (std::string::iterator i = stringToLower.begin(); i != stringToLower.end(); i++)
    {
        *i = converToLower(*i);
    }
    return stringToLower;
}