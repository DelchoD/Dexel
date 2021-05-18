#include "Cell.h"
#include<iostream>
#include <iomanip>
Cell::Cell():cellContent("") {
}

Cell::Cell(std::string _cellContent) : cellContent(_cellContent) {
}

Cell::Cell(const Cell& rhs) : cellContent(rhs.cellContent) {
}

Cell& Cell::operator=(Cell& rhs)
{
	std::swap(cellContent, rhs.cellContent);
	return *this;
}

void Cell::print(int width) const
{
	std::cout << std::setw(width) << cellContent;
}
