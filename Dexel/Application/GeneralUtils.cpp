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
bool readForEdit(const char* editionValues, int& row, int& column, int& endRef)
{
	int index = 0;
	for (index; editionValues[index] == ' '; ++index);
	bool sign = true;
	if (editionValues[index] == '-') 
	{
		++index;
		sign = false;
	}
	int columnT{}, rowT{};
	if (IsTableRowIndex(editionValues[index]))
	{
		if (editionValues[index]>='a'&&editionValues[index]<='z')
		{
			columnT = editionValues[index] - '`';
		}
		else if (editionValues[index] >= 'A' && editionValues[index] <= 'Z')
		{
			columnT = editionValues[index] - '@';
		}	
	}
	else 
	{
		return false;
	}
	if (IsNumber(editionValues[index++]))
	{
		rowT = editionValues[index] - '0';;
	}
	row = rowT;
	column = columnT;
	endRef = 2;
	return true;
}

bool isOperator(char symbol)
{
	return symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/' || symbol == '^';
}

bool IsTableRowIndex(char symbol)
{
	if ((symbol>='a'&&symbol<='z')||(symbol >= 'A' && symbol <= 'Z'))
	{
		return true;
	}
}
bool IsNumber(char symbol)
{
	if ((symbol >= 'a' && symbol <= 'z') || (symbol >= 'A' && symbol <= 'Z'))
	{
		return true;
	}
}
