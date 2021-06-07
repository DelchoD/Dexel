#pragma once
#include <iostream>
#include <vector>
#include "Cell.h"
//#include "TableInterface.h"
class Table;
class Row
{
private:
	std::vector<Cell*> cellsPerRow;
	const TableInterface* transfer;
	bool readRow(const char *source, char *buffer,int* length=nullptr)const;
	Cell* createCell(const char* cellCont)const;
public:
	Row();
	Row(char *rowValue, const TableInterface* _transfer);
	Row(const Row& rhs);
	Row& operator=(const Row& rhs);
	~Row();

	Cell* getCell(int columnIndex) const;
	void print()const;
	//int getNumberOfCellsPerRow();
	void writeToFile(std::fstream& writer)const;
	void setCell(int columnIndex, const char *_cellEditedContent);
	
};

