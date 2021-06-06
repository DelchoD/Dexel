#include "DoubleCell.h"

DoubleCell::DoubleCell(const char* _cellContent):Cell(_cellContent)
{
	size_t index = 0;
	for (cellContent; cellContent[index] != ' '&& cellContent[index]!='\0'; ++index);
	*cellContent = '\0';
}

//void DoubleCell::writeToFile(std::fstream& writer)
//{
//}
//
//void DoubleCell::print()
//{
//	
//}

Cell* DoubleCell::copyCell()
{
	return new DoubleCell(*this);
}