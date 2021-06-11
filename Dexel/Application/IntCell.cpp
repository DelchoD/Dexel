#include "IntCell.h"
#include <fstream>
IntCell::IntCell(const char* _cellContent) :Cell(_cellContent)
{
	size_t index = 0;
	cellValueAsInt = atoi(cellContent);
}

void IntCell::writeToFile(std::fstream& writer)
{
	writer << cellValueAsInt;
}

void IntCell::print()
{
	std::cout << cellValueAsInt;
}

double IntCell::examine() const
{
	return cellValueAsInt;
}

Cell* IntCell::copyCell()
{
	return new IntCell(*this);
}
