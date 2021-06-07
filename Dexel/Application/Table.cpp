#include "Table.h"
#include "Row.h"
#include <string>
#include <iostream>
#include <fstream>
void Table::setColumnWidth()
{
	int maxRowLen = 0;

	for (int i = 0; i < tableRows.size(); i++)
	{
		int rowCells = tableRows[i].getNumberOfCellsPerRow();
		if (maxRowLen < rowCells) 
		{
			maxRowLen = rowCells;
		}
	}

	columnWidths = std::vector<int>(maxRowLen);

	for (int i = 0; i < maxRowLen; i++) 
	{
		columnWidths.push_back(0);
	}

	for (int i = 0; i < tableRows.size(); i++)
	{
		for (int j = 0; j < tableRows[i].getNumberOfCellsPerRow(); j++)
		{
			int cellStrLen = getCell(i, j)->getCellLength();
			if (columnWidths[j] < cellStrLen) 
			{
				columnWidths[j] = cellStrLen;
			}
		}
	}
}
void Table::print() const
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

void Table::writeToFile(std::fstream& writer) const
{
	for (size_t i = 0; i < tableRows.size(); i++)
	{
		tableRows[i].writeToFile(writer);
	}
}

CellInterface* Table::getCell(int rowIndex, int columnIndex) const
{
	return tableRows[rowIndex].getCell(columnIndex);
}

bool Table::parseFromFile(std::istream& reader)  //can convert from fstream to istream
{
	char temp[1024]{};
	while (reader.getline(temp,(std::streamsize)1024))
	{
		tableRows.push_back(Row(temp,this));
	}
	setColumnWidth();
	return true;
}

int Table::getColumnWidth(int columnIndex) const
{
	return columnWidths[columnIndex];
}
