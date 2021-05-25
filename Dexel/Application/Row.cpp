#include "Row.h"
#include <fstream>
bool Row::readRow(std::string source, std::string buffer, int* length)
{
	size_t index = 0;
	for (index; source[index] != ',' && source[index] != '\0'; index++)
	{
		buffer[index] = source[index];
	}
	buffer[index] = '\0';
	*length = ++index;

	return source[index] != '\0';
}

Row::Row()
{
}

Row::Row(std::string rowValue)
{
	std::string tempReader = rowValue, tempBuffer;
	int position = 0;
	while (readRow(tempReader, tempBuffer, &position))
	{
		tempReader += position;
	}
}

Row::Row(const Row& rhs)
{
	cellsPerRow = rhs.cellsPerRow;
	for (size_t i = 0; i < cellsPerRow.size(); i++)
	{
		cellsPerRow[i] = cellsPerRow[i]->copyCell();
	}
}

Row& Row::operator=(const Row& rhs)
{
	if (this != &rhs)
	{
		cellsPerRow = rhs.cellsPerRow;
		for (size_t i = 0; i < cellsPerRow.size(); i++)
		{
			cellsPerRow[i] = cellsPerRow[i]->copyCell();
		}
	}
	return *this;
}

Row::~Row()
{
	for (size_t i = 0; i < cellsPerRow.size(); i++)
	{
		delete cellsPerRow[i];
	}
}

void Row::print()
{
	for (size_t i = 0; i < cellsPerRow.size(); i++)
	{
		cellsPerRow[i]->print(0);
	}
}

void Row::writeToFile(std::fstream& writer)
{
	for (size_t i = 0; i < cellsPerRow.size(); i++)
	{
		cellsPerRow[i]->writeToFile(writer);
	}
}

void Row::setCell(int columnIndex, const std::string _cellEditedContent)
{
	cellsPerRow[columnIndex]->setContent(_cellEditedContent);
}
