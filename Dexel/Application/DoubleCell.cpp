#include "DoubleCell.h"

DoubleCell::DoubleCell(const char* _cellContent):Cell(_cellContent)
{
	size_t index = 0;
	/*for (cellContent; cellContent[index] != ' '&& cellContent[index]!='\0'; ++index);
	cellContent[index] = '\0';
	
	cellValueAsDouble = parseDouble(cellContent);*/
	cellValueAsDouble = atof(cellContent);
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