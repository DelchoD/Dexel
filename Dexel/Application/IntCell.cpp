#include "IntCell.h"

IntCell::IntCell(std::string _cellContent):Cell(_cellContent)
{
	_cellContent = trim(_cellContent);
	cellValueAsInt = parseInt(_cellContent);
}

Cell* IntCell::copyCell()
{
	return new IntCell(*this);
}
