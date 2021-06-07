#pragma once
#include <string>
#include "CellInterface.h"
#include "TableInterface.h"
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
	virtual double examine() const = 0;
	virtual void writeToFile(std::fstream& writer) const;
	virtual void print(int cellWidth)const;
	virtual int getCellLength() const;
	virtual Cell* copyCell() = 0;
	virtual ~Cell();
};

