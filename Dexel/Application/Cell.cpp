#include "Cell.h"
#include<iostream>
#include <fstream>
#include <iomanip>
Cell::Cell() :cellContent(nullptr)
{
}

Cell::Cell(const char* _cellContent) : cellContent(nullptr)
{
	cellContent = new char[strlen(_cellContent) + 1];
	strcpy(cellContent, _cellContent);
}

Cell::Cell(const Cell& rhs) : cellContent(nullptr)
{
	cellContent = new char[strlen(rhs.cellContent) + 1];
	strcpy(cellContent, rhs.cellContent);
}

Cell& Cell::operator=(Cell& rhs)
{
	if (this != &rhs)
	{
		delete cellContent;
		cellContent = new char[strlen(rhs.cellContent) + 1];
		strcpy(cellContent, rhs.cellContent);
	}
	return *this;
}


void Cell::writeToFile(std::fstream& writer) const
{
	writer << cellContent;
}

void Cell::print(int cellWidth) const
{
	std::cout << std::setw(cellWidth) << cellContent;
}

int Cell::getCellLength() const
{
	return strlen(cellContent);
}

Cell::~Cell()
{
	//delete[] cellContent;
}

std::ostream& operator<<(std::ostream& out, const Cell& rhs)
{
	out << rhs.cellContent;
	return out;
}
