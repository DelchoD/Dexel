#include "Cell.h"
#include <iostream>
#include <algorithm>
Cell::Cell(int _rowIndexconst, int _columnIndex, std::string _cellContent):rowIndex(_rowIndexconst), columnIndex(_columnIndex),cellContent(_cellContent)
{
}

Cell::Cell(const Cell& rhs)
{
		rowIndex = rhs.rowIndex;
		columnIndex = rhs.columnIndex;
		cellContent = rhs.cellContent;
}

Cell& Cell::operator=(Cell& rhs)//strong exeption gurantee
{
	std::swap(rowIndex, rhs.rowIndex);
	std::swap(columnIndex, rhs.columnIndex);
	std::swap(cellContent, rhs.cellContent);
}

int Cell::getColumnIndex() const
{
	return columnIndex;
}

int Cell::getRowIndex() const
{
	return rowIndex;
}

std::string Cell::getCellContent() const
{
	return cellContent;
}
