#include "IntCell.h"

IntCell::IntCell(const char* _cellContent):Cell(_cellContent)
{
	size_t index = 0;
	for (cellContent; cellContent[index] != ' ' && cellContent[index] != '\0'; ++cellContent);
	*cellContent = '\0';
	bool hasSign = cellContent[0] != '-';
	int number = 0;
	for (index = (cellContent[0] == '-') ? 1 : 0; cellContent[index] != '\0'; index++) 
	{
		number *= 10;
		number += cellContent[index] - '0';
	}

	cellValueAsInt = hasSign ? number : -number;

}

//void IntCell::writeToFile(std::fstream& writer)
//{
//}
//
//void IntCell::print()
//{
//}

double IntCell::examine()
{
	return cellValueAsInt;
}

Cell* IntCell::copyCell()
{
	return new IntCell(*this);
}
