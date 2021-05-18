#include "DoubleCell.h"

DoubleCell::DoubleCell(std::string _cellContent):Cell(_cellContent)
{
	_cellContent = trim(_cellContent);
	cellValueAsDouble = parseDouble(_cellContent);
}

Cell* DoubleCell::copyCell()
{
	return new DoubleCell(*this);
}