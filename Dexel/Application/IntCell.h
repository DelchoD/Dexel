#pragma once
#include "Cell.h"
#include "CellUtils.h"
class IntCell : public Cell
{
private:
	int cellValueAsInt{};
public:
	IntCell(const char* _cellContent);
	//virtual void writeToFile(std::fstream& writer);
	//virtual void print();
	virtual double examine()const;
	virtual Cell* copyCell();
};

