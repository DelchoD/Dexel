#include "CellUtils.h"
#include <string>
TypeOfCell findCellType(std::string _cellContent)
{
	std::string temp = _cellContent;
	size_t index = 0;
	bool integer = true, doubles = true;
	short numberOfDecimals = 0;

	//skipws is an alternative use it with sstream
	for (index; temp[index] == ' '; index++);

	if (temp[index] == '=')
	{
		return TypeOfCell::Formula;
	}
	else if (temp[index] == '\0')
	{
		return TypeOfCell::String; //alternatively add Empty
	}
	else if (temp[index] == '+' || temp[index] == '-')
	{
		if (!isDigit(temp[index + 1]))
		{
			return TypeOfCell::String; //add error
		}
		for (++index; isDigit(temp[index]) || temp[index] == '.'; index++)
		{
			if (temp[index] == '.')
			{
				integer = false;
				numberOfDecimals++;
			}
			if (numberOfDecimals >= 2)
			{
				return TypeOfCell::String; //add error
			}
		}
		if (numberOfDecimals==0)
		{
			doubles = false;
		}
		if (temp[index]!='\0')
		{
			for (++index; temp[index] == ' '; index++);
		}
			if (temp[index] == '\0')
			{
				if (integer)
				{
					return TypeOfCell::Integer;
				}
				else if (doubles)
				{
					return TypeOfCell::Double;
				}
			}
	}
	else if (temp[index] == '\"')
	{
		index++;
		while (temp[index]!='\0'&&temp[index]!='\"')
		{
			index++;
		}
		if (temp[index]=='\0')
		{
			return TypeOfCell::Unknown;
		}
		else
		{
			if (temp[index]=='\"')
			{
				index++;
				while (temp[index] == ' ')
				{
					index++;
				}
				if (temp[index]=='\0')
				{
					return TypeOfCell::String;
				}
				else
				{
					return TypeOfCell::Unknown;
				}
			}
		}
	}
	else
	{
		return TypeOfCell::String;
	}
}

std::string trim(std::string trimmedValue)
{
	std::size_t startPos = trimmedValue.find_first_not_of(" \t"); //should it be(" \t\n\v")
	std::size_t finalPos = trimmedValue.find_last_not_of(" \t"); //should it be(" \t\n\v")

	if (startPos == std::string::npos || finalPos == std::string::npos)
	{
		return "";
	}

	return trimmedValue.substr(startPos, finalPos - startPos + 1);
}

int parseInt(std::string valueToExamine)
{
	return std::stoi(valueToExamine);
}

double parseDouble(std::string valueToExamine)
{
	return std::stod(valueToExamine);
}

bool isDigit(char symbol)
{
	return symbol >= '0' && symbol <= '9';
}
