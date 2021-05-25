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
	void edit(int rowIndex,int columnIndex, const std::string newContent);
	void writeToFile(std::fstream& writer);
	bool parseFromFile(std::istream& reader);
};

