#pragma once
#include <string>
class Cell
{
protected:
	std::string cellContent;
public:
	Cell();
	Cell(std::string _cellContent);
	Cell(const Cell& rhs);
	Cell& operator=(Cell& rhs);

	virtual void print(int width) const;
	virtual Cell* copyCell() const = 0;
};

