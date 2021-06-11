#include "DoubleCell.h"
#include <fstream>
DoubleCell::DoubleCell(const char* _cellContent) :Cell(_cellContent)
{
	size_t index = 0;
	cellValueAsDouble = atof(cellContent);
}

void DoubleCell::writeToFile(std::fstream& writer)
{
	writer << cellValueAsDouble;
}

void DoubleCell::print()
{
	std::cout << cellValueAsDouble;
}

double DoubleCell::examine() const
{
	return cellValueAsDouble;
}

Cell* DoubleCell::copyCell()
{
	return new DoubleCell(*this);
}