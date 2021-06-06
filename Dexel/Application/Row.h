#pragma once
#include <iostream>
#include <vector>
#include "Cell.h"
class Row
{
private:
	std::vector<Cell*> cellsPerRow;
	bool readRow(const char *source, char *buffer,int* length=nullptr);
	Cell* getCell(const char* cellCont);
public:
	Row();
	Row(char *rowValue);
	Row(const Row& rhs);
	Row& operator=(const Row& rhs);
	~Row();

	void print();
	//int getNumberOfCellsPerRow();
	void writeToFile(std::fstream& writer);
	void setCell(int columnIndex, const char *_cellEditedContent);
	
};

