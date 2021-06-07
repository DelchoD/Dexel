#include "IntCell.h"

IntCell::IntCell(const char* _cellContent):Cell(_cellContent)
{
	size_t index = 0;
	for (cellContent; cellContent[index] != ' ' && cellContent[index] != '\0'; ++cellContent);
	*cellContent = '\0';

	cellValueAsInt = parseInt(cellContent);
}

//void IntCell::writeToFile(std::fstream& writer)
//{
//}
//
//void IntCell::print()
//{
//}

double IntCell::examine() const
{
	return cellValueAsInt;
}

Cell* IntCell::copyCell()
{
	return new IntCell(*this);
}
