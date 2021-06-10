#pragma once
#include "Cell.h"
#include "CellUtils.h"
/**
* \class DoubleCell
 * @brief Class DoubleCell represents a double type of cell of the class Cell
*/
class DoubleCell : public Cell
{
private:
	double cellValueAsDouble{};/**< The value of the cell stored in double */
public:
	/**
	* DoubleCell constructor with one parameter
	 * @brief This is the parameter constructor for DoubleCell
	 * @param _cellContent The value which is going to initialize the Cell
	*/
	DoubleCell(const char* _cellContent);

	virtual void writeToFile(std::fstream& writer);
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

