#include "Row.h"
#include "IntCell.h"
#include "DoubleCell.h"
#include "StringCell.h"
#include "FormulaCell.h"
#include "CellUtils.h"
#include "Table.h"
#include <fstream>
#include <cstring>
bool Row::readRow(const char *source, char *buffer, int* length) const
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
	*length = source[index] == ',' ? (int)(index + 1) : (int)(index);
	//*length = (int)(++index);

	return true;
}

Row::Row():transfer(nullptr)
{
}

Row::Row(char *rowValue, TableInterface* _transfer):transfer(_transfer)
{
	char* rowParser = rowValue;
	char buffer[1024];
	int offset = 0;
	while (readRow(rowParser, buffer, &offset)) 
	{
		rowParser += offset;
		Cell* newCell = createCell(buffer);
		cellsPerRow.push_back(newCell);
	}
}

Row::Row(const Row& rhs):transfer(rhs.transfer)
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
		transfer = rhs.transfer;
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

Cell* Row::getCell(int columnIndex) const
{
	return cellsPerRow[columnIndex];
}

void Row::print() const
{
	for (size_t i = 0; i <= cellsPerRow.size(); i++)
	{
		if (i==cellsPerRow.size())
		{
			std::cout << " |";
			break;
		}
		if (i != 0)
		{
			std::cout << " |";
		}
		cellsPerRow[i]->print(transfer->getColumnWidth((int)i));
	}
	std::cout << "\n";
}

int Row::getNumberOfCellsPerRow() const
{
	return (int)(cellsPerRow.size());
}

void Row::writeToFile(std::fstream& writer) const
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
	cellsPerRow[columnIndex] = createCell(_cellEditedContent);
}

Cell* Row::createCell(const char *cellCont) const
{
	char* parser=const_cast<char*>(cellCont);

	for (; *parser == ' '; ++parser);


	switch (findCellType(parser))
	{
	case TypeOfCell::Integer:
		return new IntCell(parser);
	case TypeOfCell::Double:
		return new DoubleCell(parser);
	case TypeOfCell::String:
		return new StringCell(parser);
	case TypeOfCell::Formula:
		return new FormulaCell(parser,transfer);
	case TypeOfCell::Empty:
		return new StringCell(parser);
	case TypeOfCell::Unknown:
		return new StringCell("ERROR");
	default:
		break;
	}
}
