#include "CellUtils.h"
#include <string>
TypeOfCell findCellType(char* _cellContent)
{
	char* temp = _cellContent;
	bool integer = true, doubles = true;
	short numberOfDecimals = 0;

	//skipws is an alternative use it with sstream
	//for (temp; *temp == ' '; ++temp);

	if (*temp == '=')
	{
		return TypeOfCell::Formula;
	}
	else if (*temp == '\0')
	{
		return TypeOfCell::Empty; //alternatively add Empty
	}
	else if (*temp=='\"')
	{
		return TypeOfCell::String;
	}
	size_t index = ((temp[0] == '-' || temp[0] == '+') && temp[1] != '\0' && isDigit(temp[1])) ? 1 : 0;
	
	for (index; temp[index] != '\0' && (isDigit(temp[index]) || temp[index] == '.'); ++index) 
	{
		if (temp[index] == '.') 
		{
			integer ? integer = false : doubles = false;
		}
	}

	for (; temp[index] == ' '; ++index);
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
	return TypeOfCell::Unknown;
}


bool isDigit(char symbol)
{
	return symbol >= '0' && symbol <= '9';
}
