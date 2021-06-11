#include "Table.h"
#include "Row.h"
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
void Table::setColumnWidth()
{
	int maxRowLen = getMaximunCellsPerRow();

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

void Table::print()
{
	int maxRowLen = getMaximunCellsPerRow();
	setColumnWidth();
	for (size_t i = 0; i <= maxRowLen; i++)
	{
		if (i<maxRowLen)
		{
			std::cout << "  |" << (char)('A' + i) << std::setw(columnWidths[i]+1) ;
		}
		else
		{
			std::cout << "  |" << (char)(' ') << std::setw(columnWidths[i] - 2) << " ";
		}
	}

	std::cout << "\n";
	for (size_t i = 0; i < tableRows.size(); i++)
	{
		std::cout << (i + 1) << " |";
		tableRows[i].print();
	}
}

void Table::edit(int rowIndex, int columnIndex, const char* newContent)
{
	tableRows.at(rowIndex).setCell(columnIndex, newContent);
}

void Table::restart()
{
	tableRows.clear();
	columnWidths.clear();
}

void Table::writeToFile(std::fstream& writer) const
{
	for (size_t i = 0; i < tableRows.size(); i++)
	{
		tableRows[i].writeToFile(writer);
		writer << "\n";
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
		try
		{
			tableRows.push_back(Row(temp, this));
		}
		catch (const std::invalid_argument& e)
		{
			std::cout <<"There is a problem with the input data on row " << (tableRows.size() + 1)<<" - it is not supported data type" << "\n";
			Table::restart();
			return false;
		}
	}
	setColumnWidth();
	return true;
}

int Table::getColumnWidth(int columnIndex) const
{
	return columnWidths[columnIndex];
}

int Table::getMaximunCellsPerRow() const
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
	return maxRowLen;
}

bool Table::isEmpty()
{
	return tableRows.empty();
}

void Table::resize(int rowsTotal, int columnTotal)
{
	tableRows.resize(rowsTotal);
	for (size_t i = 0; i < tableRows.size(); i++)
	{
		if (tableRows.at(i).getTransfer() != nullptr)
		{
			tableRows.at(i).resize(columnTotal);
		}
		else
		{
			tableRows.at(i).setTransfer(tableRows.at(i - 1).getTransfer());
			tableRows.at(i).resize(columnTotal);
		}
	}
	setColumnWidth();
}