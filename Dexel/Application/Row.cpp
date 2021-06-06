#include "Row.h"
#include "IntCell.h"
#include "DoubleCell.h"
#include "StringCell.h"
#include "FormulaCell.h"
#include "CellUtils.h"
#include <fstream>
bool Row::readRow(const char *source, char *buffer, int* length)
{
	size_t index = 0;
	if (*source == '\0') 
	{
		return false;
	}
	for (index; source[index] != ',' && source[index] != '\0'; index++)
	{
		buffer[index] = source[index];
	}
	buffer[index] = '\0';
	*length = source[index] == ',' ? index + 1 : index;
	*length = ++index;

	return true;
}

Row::Row()
{
}

Row::Row(char *rowValue)
{
	char* rowReader = rowValue;
	char buffer[1024];
	int offset = 0;
	while (readRow(rowReader, buffer, &offset)) 
	{
		rowReader += offset;
		Cell* newCell = getCell(buffer);
		cellsPerRow.push_back(newCell);
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
		if (i != 0)
		{
			std::cout << ", ";
		}
		cellsPerRow[i]->print();
	}
}

void Row::writeToFile(std::fstream& writer)
{
	for (size_t i = 0; i < cellsPerRow.size(); i++)
	{
		if (i!=0)
		{
			writer<< ", ";
		}
		cellsPerRow[i]->writeToFile(writer);
	}
}

void Row::setCell(int columnIndex, const char *_cellEditedContent)
{
	cellsPerRow[columnIndex] = getCell(_cellEditedContent);
}

Cell* Row::getCell(const char *cellCont)
{
	const char* reader = cellCont;
	for (; *reader == ' '; ++reader);

	if (*reader == '\0') {
		return new StringCell("");
	}
	if (*reader == '=') {
		return new FormulaCell(reader);
	}

	bool isInteger = true;
	bool isDouble = true;
	size_t i = 0;
	for (; reader[i] != '\0' && (isDigit(reader[i]) || reader[i] == '.'); ++i) {
		if (reader[i] == '.') {
			isInteger ? isInteger = false : isDouble = false;
		}
	}
	for (; reader[i] == ' '; ++i);
	if (reader[i] == '\0') {
		if (isInteger) {
			return new IntCell(reader);
		}
		else if (isDouble) {
			return new DoubleCell(reader);
		}
	}

	return new StringCell(reader);
}
