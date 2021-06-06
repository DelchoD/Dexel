#pragma once
#include "Cell.h"
class FormulaCell : public Cell
{
private:
public:
	FormulaCell(const char* _cellContent);
	/*virtual void writeToFile(std::fstream& writer);
	virtual void print();*/
	virtual Cell* copyCell();
};

