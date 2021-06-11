#pragma once
#include "Cell.h"
#include "Table.h"
/**
* \class FormulaCell
 * @brief Class FormulaCell represents a formula type of cell of the class Cell
*/
class FormulaCell : public Cell
{
private:
	Cell* cellsToUse; /**< Value for storing the reference to the actual cells */
	const TableInterface* tabletranfer;/**< Value for searching the selected cells */
	int rowFirstCell, columnFirstCell; /**< Values for storing the column and row index of the first cell of the formula, if it is not a constant */
	int rowSecondCell, columnSecondCell;/**< Values for storing the column and row index of the second cell of the formula, if it is not a constant */
	double constantOne, constantTwo;/**< Values for storing constants as a double, is there is no reference of a cell */
	char sign; /**< Variable for storing the operator in the formula */
public:
	/**
	* FormulaCell constructor with two parameters
	 * @brief With this function we can create a new FormulaCell object with given formula and table to search for the cells in it
	 * @param _cellContent Used formula
	 * @param transfer Used table reference
	*/
	FormulaCell(const char* _cellContent, const TableInterface* transfer);

	/**
	* Virtual function to examine a cell
	 * @brief By this function we can see it's type approximately
	 * @return The cell content casted to double
	*/
	virtual double examine()const;

	/**
	* Function for reading formula from a string
	 * @brief With this function we can read the content of the cell in which is the formula and split it into small pieces-references or constants
	 * @param string String used to read from
	 * @param end Index of the element after reading
	 * @param rowIndex Index of the row which is pointed by the reference if exists
	 * @param colIndex Index of the column which is pointed by the reference if exists
	*/
	void readCell(const char* string, int& end, int& rowIndex, int& colIndex);

	/**
	* Virtual function for writing in files
	 * @brief By this function we can save the content of the cell to a type of fstream stream
	 * @param writer The stream which we are going to use
	*/
	virtual void writeToFile(std::fstream& writer)const;

	/**
	* Fucntion for reading constants in a formulas
	 * @brief With this function we can read constants in the formula
	 * @param reader String from which to read
	 * @param end Index of the end of the string after we have read the costants
	 * @return Double value of the constant
	*/
	double readConstant(const char* reader, int& end) const;

	/**
	* Function for getting a cell to search for
	 * @brief With this function we can get a cell reference and search it in the table
	 * @param rowIndex The row index of the selected cell
	 * @param columnIndex The column index of the selected cell
	 * @return Pointer to the content of the cell
	*/
	CellInterface* getCell(int rowIndex, int columnIndex) const;

	/**
	* Virtual function for printing the cell
	 * @brief By this function we can print the content to the cell to the default std::cout stream
	 * @param cellWidth Width if the cell, which is used for aligning later
	*/
	virtual void print(int cellWidth) const;

	/**
	* Virtual function for copying a cell
	 * @brief By this function we can copy one cell to another not in the way to make new object
	 * @return Pointer to the selected cell
	*/
	virtual Cell* copyCell();
};

