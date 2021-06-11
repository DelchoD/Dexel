#pragma once
/**
* \class CellInterface
 * @brief Class CellInterface used to unite some operations performed by all types of cells
*/
class CellInterface
{
public:
	/**
	* Virtual function to examine a cell
	 * @brief By this function we can see it's type approximately
	 * @return The cell content casted to double
	*/
	virtual double examine() const = 0;

	/**
	* Virtual function for getting the length of the cell content
	 * @brief By this function we can get the length of the cell, no matter it's type
	 * @return Int value - the width of the cell in decimal places
	*/
	virtual int getCellLength() const=0;
};

