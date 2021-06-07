#pragma once
#include <vector>
#include "Row.h"
#include "GeneralUtils.h"
#include "CellInterface.h"
#include "TableInterface.h"
class Table : public TableInterface
{
private:
	std::vector<Row> tableRows;
	std::vector<int> columnWidths;
	void setColumnWidth();
public:
	void print()const;
	void edit(int rowIndex,int columnIndex, const char* newContent);
	void restart();
	void writeToFile(std::fstream& writer) const;
	CellInterface* getCell(int row, int col) const;
	bool parseFromFile(std::istream& reader); //check this twice
	int getColumnWidth(int columnIndex) const;
};

