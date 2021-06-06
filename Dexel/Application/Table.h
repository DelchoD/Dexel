#pragma once
#include <vector>
#include "Row.h"
#include "GeneralUtils.h"
class Table
{
private:
	std::vector<Row> tableRows;
public:
	void print();
	void edit(int rowIndex,int columnIndex, const char* newContent);
	void restart();
	void writeToFile(std::fstream& writer);
	bool parseFromFile(std::istream& reader); //check this twice
};

