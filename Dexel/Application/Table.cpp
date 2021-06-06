#include "Table.h"
#include "Row.h"
#include <string>
#include <iostream>
#include <fstream>
void Table::print()
{
	for (size_t i = 0; i < tableRows.size(); i++)
	{
		tableRows[i].print();
	}
}

void Table::edit(int rowIndex, int columnIndex, const char* newContent)
{
	tableRows[rowIndex].setCell(columnIndex, newContent);
}

void Table::restart()
{
	tableRows.clear();
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
	char temp[1024]{};
	while (reader.getline(temp,(std::streamsize)1024))
	{
		tableRows.push_back(Row(temp));
	}
	return true;
}
