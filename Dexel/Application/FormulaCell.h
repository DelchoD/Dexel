#pragma once
#include "Cell.h"
#include "Table.h"
class FormulaCell : public Cell
{
private:
	Cell* cellsToUse;
	const TableInterface* tabletranfer;
	int rowFirstCell, columnFirstCell;
	int rowSecondCell, columnSecondCell;
	char sign;
public:
	FormulaCell(const char* _cellContent, const TableInterface* transfer);
	virtual double examine()const;
	void getCell(const char* string, int& end, int& rowIndex, int& colIndex);
	virtual void writeToFile(std::fstream& writer)const;
	virtual void print(int cellWidth) const;
	virtual Cell* copyCell();
};

