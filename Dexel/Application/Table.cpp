#include "Table.h"
#include "Row.h"
#include <string>
#include <iostream>
void Table::print()
{
	for (size_t i = 0; i < tableRows.size(); i++)
	{
		tableRows[i].print();
	}
}

void Table::edit(int rowIndex, int columnIndex, const std::string newContent)
{
	tableRows[rowIndex].setCell(columnIndex, newContent);
}

void Table::writeToFile(std::fstream& writer)
{
	for (size_t i = 0; i < tableRows.size(); i++)
	{
		tableRows[i].writeToFile(writer);
	}
}

bool Table::parseFromFile(std::istream& reader)  //can convert from fstream to istream
{
	std::string buffer;
	
	while (std::getline(reader,buffer));
	{
		tableRows.push_back(Row(buffer));
	}
	return true;
}
