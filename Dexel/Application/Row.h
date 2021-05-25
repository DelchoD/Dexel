#pragma once
#include <iostream>
#include <vector>
#include "Cell.h"
class Row
{
private:
	std::vector<Cell*> cellsPerRow;
	bool readRow(std::string source, std::string buffer,int* length);
public:
	Row();
	Row(std::string rowValue);
	Row(const Row& rhs);
	Row& operator=(const Row& rhs);
	~Row();

	void print();
	//int getNumberOfCellsPerRow();
	void writeToFile(std::fstream& writer);
	void setCell(int columnIndex, const std::string _cellEditedContent);
	//Cell* getCell(int columnIndex);
};

