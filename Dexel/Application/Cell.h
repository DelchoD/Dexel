#pragma once
#include <string>
#include "CellInterface.h"
class Cell : public CellInterface
{
protected:
	char* cellContent;
public:
	Cell();
	Cell(const char* _cellContent);
	Cell(const Cell& rhs);
	Cell& operator=(Cell& rhs);
	//virtual void setContent(const char* cellNewContent) = 0;
	friend std::ostream& operator<<(std::ostream& out, const Cell& rhs);
	virtual double examine() = 0;
	virtual void writeToFile(std::fstream& writer);
	virtual void print();
	virtual Cell* copyCell() = 0;
	virtual ~Cell();
};

