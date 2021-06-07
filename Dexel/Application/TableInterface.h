#pragma once
#include "CellInterface.h"
class TableInterface
{
public:
	virtual CellInterface* getCell(int row, int col) const = 0;
	virtual int getColumnWidth(int columnIndex) const = 0;
};

