#pragma once
#include <vector>
#include "Row.h"
#include "GeneralUtils.h"
class Table
{
private:
	std::vector<Row> tableRows;
public:
	void print()const;
	void edit(int rowIndex,int columnIndex, const char* newContent);
	void restart();
	void writeToFile(std::fstream& writer) const;
	Cell* getCell(int row, int col) const;
	bool parseFromFile(std::istream& reader); //check this twice
};

