#pragma once
#include "Cell.h"
#include "CellUtils.h"
class DoubleCell : public Cell
{
private:
	double cellValueAsDouble;
public:
	DoubleCell(std::string _cellContent);
	virtual Cell* copyCell();
};

