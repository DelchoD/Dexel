#pragma once
#include "Cell.h"
#include "CellUtils.h"

class StringCell : public Cell
{
private:
public:
	StringCell(const char* _cellContent);
	/*virtual void writeToFile(std::fstream& writer);
	virtual void print();*/
	virtual double examine()const;
	virtual Cell* copyCell();
};

