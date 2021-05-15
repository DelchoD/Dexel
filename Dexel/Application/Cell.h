#pragma once
#include <string>
class Cell
{
protected:
	int columnIndex{};
	int rowIndex{};
	std::string cellContent{};
public:
	Cell(int _rowIndexconst,int _columnIndex, std::string _cellContent);
	Cell(const Cell& rhs);
	Cell& operator=(Cell& rhs);

	int getColumnIndex() const;
	int getRowIndex() const;
	std::string getCellContent() const;

	virtual void printContent() = 0;
};

