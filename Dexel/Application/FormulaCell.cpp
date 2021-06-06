#include "FormulaCell.h"
#include <iostream>
FormulaCell::FormulaCell(const char* _cellContent): Cell(_cellContent)
{
	char* reader = cellContent;
	for (reader; *reader != ' '; ++reader);
	*reader = '\0';
}

//void FormulaCell::writeToFile(std::fstream& writer)
//{
//}
//
//void FormulaCell::print()
//{
//}

Cell* FormulaCell::copyCell()
{
	return new FormulaCell(*this);
}
