#include "DoubleCell.h"

DoubleCell::DoubleCell(const char* _cellContent):Cell(_cellContent)
{
	size_t index = 0;
	for (cellContent; cellContent[index] != ' '&& cellContent[index]!='\0'; ++index);
	*cellContent = '\0';
	bool hasSign = cellContent[0] != '-';
	double number = 0;
	int exp = 1;
	bool afterDecimalPoint = false;
	index = (cellContent[0] == '-') ? 1 : 0;
	for (index; cellContent[index] != '\0'; index++) 
	{
		if (cellContent[index] == '.') 
		{
			afterDecimalPoint = true;
		}
		else 
		{
			number *= 10;
			number += cellContent[index] - '0';
			if (afterDecimalPoint) 
			{
				exp *= 10;
			}
		}
	}

	cellValueAsDouble = hasSign ? number / exp : -(number / exp);
}

//void DoubleCell::writeToFile(std::fstream& writer)
//{
//}
//
//void DoubleCell::print()
//{
//	
//}

double DoubleCell::examine() const
{
	return cellValueAsDouble;
}

Cell* DoubleCell::copyCell()
{
	return new DoubleCell(*this);
}