#pragma once

#include <iostream>
#include <vector>
#include "Cell.h"
class Row
{
private:
	std::vector<std::shared_ptr<Cell>> cellsPerRow;
public:
	Row();
	Row(const Row& rhs);
	Row& operator=(const Row& rhs);
	~Row();

	void print();
	int getNumberOfCellsPerRow();
	void setCell(int columnIndex, const std::string _cellEditedContent);
	std::shared_ptr<Cell> getCell(int columnIndex);
};

