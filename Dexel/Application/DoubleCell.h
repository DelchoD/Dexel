#pragma once
#include "Cell.h"
#include "CellUtils.h"
class DoubleCell : public Cell
{
private:
	double cellValueAsDouble{};
public:
	DoubleCell(const char* _cellContent);
	/*virtual void writeToFile(std::fstream& writer);
	virtual void print();*/
	virtual double examine()const;
	virtual Cell* copyCell();

};

