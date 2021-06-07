#include "FormulaCell.h"
#include "GeneralUtils.h"
#include <cmath>
#include <iostream>
#include <iomanip>
#include <fstream>
FormulaCell::FormulaCell(const char* _cellContent, const TableInterface* transfer) : Cell(_cellContent), tabletranfer(transfer)
{
	char* reader = cellContent;
	for (reader; *reader != ' '; ++reader);
	*reader = '\0';
	int end = 0;
	for (; !IsTableRowIndex (*reader); ++reader);
	getCell(reader, end, rowFirstCell, columnFirstCell);
	reader += end;

	for (; !isOperator(*reader); reader++);
	sign = *reader;

	for (++reader; !IsTableRowIndex(*reader); ++reader);
	getCell(reader, end, rowSecondCell, columnSecondCell);
}

double FormulaCell::examine()const
{
	double operand1 = tabletranfer->getCell(rowFirstCell - 1, columnFirstCell - 1)->examine();
	double operand2 = tabletranfer->getCell(rowSecondCell - 1, columnSecondCell - 1)->examine();
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

void FormulaCell::getCell(const char* string, int& end, int& rowIndex, int& columnIndex)
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
	double checkForNULL = tabletranfer->getCell(rowSecondCell - 1, columnSecondCell - 1)->examine();
	if (sign == '/' && checkForNULL == 0)
	{
		writer << "ERROR";
	}
	else 
	{
		writer << examine();
	}
}

void FormulaCell::print(int cellWidth)const
{
	double op2 = tabletranfer->getCell(rowSecondCell - 1, columnSecondCell - 1)->examine();
	if (sign == '/' && op2 == 0) 
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
