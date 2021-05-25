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
	virtual void setContent(const std::string cellNewContent) = 0;
	virtual void writeToFile(std::fstream& writer)=0;
	virtual void print(int width)const;
	virtual Cell* copyCell() = 0;
};

