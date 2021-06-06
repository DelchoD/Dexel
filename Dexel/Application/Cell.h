#pragma once
#include <string>
class Cell
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
	virtual void writeToFile(std::fstream& writer);
	virtual void print();
	virtual Cell* copyCell() = 0;
	virtual ~Cell();
};

