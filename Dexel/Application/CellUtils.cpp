#include "CellUtils.h"
#include <string>
TypeOfCell findCellType(const char* _cellContent)
{
	const char* temp = _cellContent;
	size_t index = 0;
	bool integer = true, doubles = true;
	short numberOfDecimals = 0;

	//skipws is an alternative use it with sstream
	for (temp; *temp == ' '; ++temp);

	if (*temp == '=')
	{
		return TypeOfCell::Formula;
	}
	else if (*temp == '\0')
	{
		return TypeOfCell::String; //alternatively add Empty
	}
	int i = ((temp[0] == '-' || temp[0] == '+') && temp[1] != '\0' && isDigit(temp[1])) ? 1 : 0;
	for (; temp[i] != '\0' && (isDigit(temp[i]) || temp[i] == '.'); ++i) {
		if (temp[i] == '.') {
			integer ? integer = false : doubles = false;
		}
	}

	for (; temp[i] == ' '; ++i);
	if (temp[i] == '\0') {
		if (integer) {
			return TypeOfCell::Integer;
		}
		else if (doubles) {
			return TypeOfCell::Double;
		}
	}

	return TypeOfCell::String;
	//else if (*temp == '+' || *temp == '-')
	//{
	//	if (!isDigit(temp[index + 1]))
	//	{
	//		return TypeOfCell::String; //add error
	//	}
	//	for (++index; isDigit(*temp) || *temp == '.'; ++temp)
	//	{
	//		if (*temp == '.')
	//		{
	//			integer = false;
	//			numberOfDecimals++;
	//		}
	//		if (numberOfDecimals >= 2)
	//		{
	//			return TypeOfCell::String; //add error
	//		}
	//	}
	//	if (numberOfDecimals==0)
	//	{
	//		doubles = false;
	//	}
	//	if (*temp!='\0')
	//	{
	//		for (++index; *temp == ' '; ++temp);
	//	}
	//		if (*temp == '\0')
	//		{
	//			if (integer)
	//			{
	//				return TypeOfCell::Integer;
	//			}
	//			else if (doubles)
	//			{
	//				return TypeOfCell::Double;
	//			}
	//		}
	//}
	//else if (*temp == '\"')
	//{
	//	++temp;
	//	while (*temp!='\0'&&*temp!='\"')
	//	{
	//		++temp;
	//	}
	//	if (*temp=='\0')
	//	{
	//		return TypeOfCell::Unknown;
	//	}
	//	else
	//	{
	//		if (*temp=='\"')
	//		{
	//			++temp;
	//			while (*temp == ' ')
	//			{
	//				++temp;
	//			}
	//			if (*temp=='\0')
	//			{
	//				return TypeOfCell::String;
	//			}
	//			else
	//			{
	//				return TypeOfCell::Unknown;
	//			}
	//		}
	//	}
	//}
	//else
	//{
	//	return TypeOfCell::String;
	//}
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

int parseInt(char* valueToExamine, int* len)
{
	int i = 0;
	bool sign = valueToExamine[0] != '-';
	int number = 0;

	i = (valueToExamine[0] == '-' || valueToExamine[0] == '+') ? 1 : 0;
	for (; valueToExamine[i] != '\0'; i++) {
		number *= 10;
		number += valueToExamine[i] - '0';
	}

	return sign ? number : -number;
}

double parseDouble(char* valueToExamine, int* len)
{
	int i = 0;
	bool sign = valueToExamine[0] != '-';
	double number = 0;
	int exp = 1;
	bool afterDecimalPoint = false;

	i = (valueToExamine[0] == '-' || valueToExamine[0] == '+') ? 1 : 0;
	for (; valueToExamine[i] != '\0'; i++) {
		if (valueToExamine[i] == '.') {
			afterDecimalPoint = true;
		}
		else {
			number *= 10;
			number += valueToExamine[i] - '0';
			if (afterDecimalPoint) {
				exp *= 10;
			}
		}
	}

	return sign ? number / exp : -(number / exp);
}

bool isDigit(char symbol)
{
	return symbol >= '0' && symbol <= '9';
}
