#include "GeneralUtils.h"

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
const char* lowerred(const char* _stringToLower)
{
	std::string stringToLower = stringToLower.c_str();
	for (std::string::iterator i = stringToLower.begin(); i != stringToLower.end(); i++)
	{
		*i = converToLower(*i);
	}
	return stringToLower.c_str();
}
bool readForEdit(const char* str, char endSym, int& intHolder, int* lengthRead)
{
	int index = 0;
	for (index; str[index] == ' '; ++index);
	bool sign = true;
	if (str[index] == '-') 
	{
		++index;
		sign = false;
	}
	int number = 0;
	for (index; str[index] != endSym && str[index] != '\n' && str[index] != '\0'; index++) 
	{
		if (isDigit(str[index])) 
		{
			number *= 10;
			number += str[index] - '0';
		}
		else 
		{
			return false;
		}
	}
	intHolder = number;
	if (lengthRead != NULL) {
		*lengthRead = index;
	}
	return true;
}