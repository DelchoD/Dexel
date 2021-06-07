#include "FormulaCell.h"
#include "GeneralUtils.h"
#include <cmath>
#include <iostream>
#include <iomanip>
#include <fstream>
FormulaCell::FormulaCell(const char* _cellContent, const TableInterface* transfer)
	: Cell(_cellContent), tabletranfer(transfer),rowFirstCell(-1),columnFirstCell(-1),rowSecondCell(-1),columnSecondCell(-1)
{
	char* parser = cellContent+1;
	for (parser; *parser != ' '; ++parser);
	*parser = '\0';

	int end = 0;
	for (; *parser == ' '; ++parser);
	if (*parser == 'R') 
	{
		readCell(parser, end, rowFirstCell, columnFirstCell);
	}
	else 
	{
		constantOne = readConstant(parser, end);
	}

	parser += end;

	for (; !isOperator(*parser); parser++);
	sign = *parser;

	for (; *parser == ' '; ++parser);
	if (*parser == 'R')
	{
		readCell(parser, end, rowSecondCell, columnFirstCell);
	}
	else
	{
		constantTwo = readConstant(parser, end);
	}
}

double FormulaCell::examine()const
{
	CellInterface* cellOne = getCell(rowFirstCell, columnFirstCell);
	double operand1 = (cellOne != NULL) ? cellOne->examine() : constantOne;
	CellInterface* cellTwo = getCell(rowSecondCell, columnSecondCell);
	double operand2 = (cellTwo != NULL) ? cellTwo->examine() : constantTwo;
	//double operand1 = tabletranfer->getCell(rowFirstCell - 1, columnFirstCell - 1)->examine();
	//double operand2 = tabletranfer->getCell(rowSecondCell - 1, columnSecondCell - 1)->examine();
	switch (sign) 
	{
	case '+':
		return operand1 + operand2;
		break;
	case '-':
		return operand1 - operand2;
		break;
	case '*':
		return operand1 * operand2;
		break;
	case '/':
		return operand1 / operand2;
	case '^':
		return pow(operand1, operand2);
		break;
	}
}

void FormulaCell::readCell(const char* string, int& end, int& rowIndex, int& columnIndex)
{
	int row = 0, col = 0;
	int index = 1;
	for (; string[index] != 'C' && string[index] != '\0'; index++) 
	{
		row *= 10;
		row += string[index] - '0';
	}
	for (++index; isDigit(string[index]) && string[index] != '\0'; index++) 
	{
		col *= 10;
		col += string[index] - '0';
	}
	rowIndex = row;
	columnIndex = col;
	end = index;
}

void FormulaCell::writeToFile(std::fstream& writer) const
{
	CellInterface* cellTwo = getCell(rowSecondCell, columnSecondCell);
	double checkForNULL = (cellTwo != NULL) ? cellTwo->examine() : constantTwo;
	//double checkForNULL = tabletranfer->getCell(rowSecondCell - 1, columnSecondCell - 1)->examine();
	if (sign == '/' && checkForNULL == 0)
	{
		writer << "ERROR";
	}
	else 
	{
		writer << examine();
	}
}

double FormulaCell::readConstant(const char* reader, int& end) const
{
	char buffer[1024];
	size_t index = 0;
	for (index; !isOperator(reader[index]); index++) 
	{
		buffer[index] = reader[index];
	}
	buffer[index] = '\0';
	end = index - 1;

	switch (findCellType(buffer)) 
	{
	case TypeOfCell::Integer:
		return parseInt(buffer);
	case TypeOfCell::Double:
		return parseDouble(buffer);
	case TypeOfCell::String:
		return 0;
	case TypeOfCell::Formula:
		return 0;
	}
}

CellInterface* FormulaCell::getCell(int rowIndex, int columnIndex) const
{
	return (rowIndex >= 0) ? tabletranfer->getCell(rowIndex, columnIndex) : NULL;
}

void FormulaCell::print(int cellWidth)const
{
	CellInterface* cellTwo = getCell(rowSecondCell, columnSecondCell);
	double checkForNULL = (cellTwo != NULL) ? cellTwo->examine() : constantTwo;
	//double checkForNULL = tabletranfer->getCell(rowSecondCell - 1, columnSecondCell - 1)->examine();
	if (sign == '/' && checkForNULL == 0)
	{
		std::cout << "ERROR";
	}
	else 
	{
		std::cout << std::setw(cellWidth) << examine();
	}
}

Cell* FormulaCell::copyCell()
{
	return new FormulaCell(*this);
}
