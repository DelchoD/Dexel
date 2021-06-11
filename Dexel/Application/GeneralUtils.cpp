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

std::string lowerred(const char* _stringToLower)
{
	std::string stringToLower = _stringToLower;
	for (std::string::iterator i = stringToLower.begin(); i != stringToLower.end(); i++)
	{
		*i = converToLower(*i);
	}
	return stringToLower;
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
		if (editionValues[index] >= 'a' && editionValues[index] <= 'z')
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

	int lengthOfNumber = 0;
	index++;

	while (IsNumber(editionValues[index]))
	{
		rowT = (rowT * 10);
		rowT += editionValues[index] - '0';
		lengthOfNumber++;
		index++;
	}

	row = rowT;
	column = columnT;
	endRef = lengthOfNumber+1;
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
	return (symbol >= '0' && symbol <= '9');
}

bool isConvertable(const char* valueToExamine)
{
	char* endptr = 0;
	
	std::strtod(valueToExamine, &endptr);

	if (*endptr != '\0' || endptr == valueToExamine)
		return false;
	return true;
}
