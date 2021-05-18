#pragma once
#include "Cell.h"
#include "CellUtils.h"

class StringCell : public Cell
{
private:
public:
	StringCell(std::string _cellContent);
	virtual Cell* copyCell();
};

