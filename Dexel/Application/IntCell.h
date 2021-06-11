#pragma once
#include "Cell.h"
#include "CellUtils.h"
/**
* \class IntCell
 * @brief Class IntCell represents an int type of cell of the class Cell
*/
class IntCell : public Cell
{
private:
	int cellValueAsInt{};/**< The value of the cell stored in int */
public:
	/**
	* IntCell constructor with one parameter
	 * @brief This is the parameter constructor for IntCell
	 * @param _cellContent The value which is going to initialize the Cell
	*/
	IntCell(const char* _cellContent);

	/**
	* Function for writing in a file
	 * @brief With this function we can write the cell in a file
	 * @param writer the fstream type stream which we are going to use
	*/
	virtual void writeToFile(std::fstream& writer);

	/**
	* Function for printing the cell
	 * @brief With this function we can print the cell content to the standard stout
	*/
	virtual void print();

	/**
	* Virtual function to examine a cell
	 * @brief By this function we can see it's type approximately
	 * @return The cell content casted to double
	*/
	virtual double examine()const;

	/**
	* Virtual function for copying a cell
	 * @brief By this function we can copy one cell to another not in the way to make new object
	 * @return Pointer to the selected cell
	*/
	virtual Cell* copyCell();
};

