#pragma once
#include "CellInterface.h"
/**
* \class TableInterface
 * @brief Class TableInterface used to unite some operations performed the class table and Row also it is used for searching
*/
class TableInterface
{
public:
	/**
	* Function for getting a cell address
	 * @brief With this function we can get the adress of a cell by it's row and column index
	 * @param row The index of the row for our cell
	 * @param col The index of the column for our cell
	 * @return Pointer to the desired cell
	*/
	virtual CellInterface* getCell(int row, int col) const = 0;

	/**
	* Function for getting the length of a column
	 * @brief With this function we can get the size of each column in order they to be ordered in the print
	 * @param columnIndex The index of each column
	 * @return Int value of the size of the column
	*/
	virtual int getColumnWidth(int columnIndex) const = 0;
};

