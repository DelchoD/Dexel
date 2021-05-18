#pragma once
#include "Cell.h"
#include "CellUtils.h"
class IntCell : public Cell
{
private:
	int cellValueAsInt;
public:
	IntCell(std::string _cellContent);
	virtual Cell* copyCell();
};

