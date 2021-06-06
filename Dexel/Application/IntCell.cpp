#include "IntCell.h"

IntCell::IntCell(const char* _cellContent):Cell(_cellContent)
{
	size_t index = 0;
	for (cellContent; cellContent[index] != ' '; ++cellContent);
	*cellContent = '\0';
}

//void IntCell::writeToFile(std::fstream& writer)
//{
//}
//
//void IntCell::print()
//{
//}

Cell* IntCell::copyCell()
{
	return new IntCell(*this);
}
