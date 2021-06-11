#pragma once
#include <string>
#include "CellInterface.h"
#include "TableInterface.h"
/**
* \class Cell
 * @brief Class Cell representing  one cell in the table
*/
class Cell : public CellInterface
{
protected:
	char* cellContent;/**<variable for storing the information as a char pointer */
	/**
	* Cell default constructor
	 * @brief This is the default constructor for Cell
	*/
	Cell();

	/**
	* Cell constructor with one parameter
	 * @brief This is the parameter constructor for Cell
	 * @param _cellContent The value which is going to initialize the Cell
	*/
	Cell(const char* _cellContent);

	/**
	* Cell copy constructor
	 * @brief This is the default copy constructor for Cell
	 * @param rhs Object form which to make Cell
	*/
	Cell(const Cell& rhs);

	/**
	* Cell default copy assignment operator
	 * @brief This is the default copy assignment operator for Cell
	 * @param rhs Object form which to make Cell
	 * @return New object from class Cell with content identical to rhs
	*/
	Cell& operator=(Cell& rhs);

	/**
	* Cell default << operator
	 * @brief This is the default output operator for Cell
	 * @param rhs Object to output
	 * @param out Type of output
	 * @return Content of the cell
	*/
	friend std::ostream& operator<<(std::ostream& out, const Cell& rhs);

	/**
	* Virtual function to examine a cell
	 * @brief By this function we can see it's type approximately
	 * @return The cell content casted to double
	*/
	virtual double examine() const = 0;

	/**
	* Virtual function for writing in files
	 * @brief By this function we can save the content of the cell to a type of fstream stream
	 * @param writer The stream which we are going to use
	*/
	virtual void writeToFile(std::fstream& writer) const;

	/**
	* Virtual function for printing the cell
	 * @brief By this function we can print the content to the cell to the default std::cout stream
	 * @param cellWidth Width if the cell, which is used for aligning later
	*/
	virtual void print(int cellWidth)const;

	/**
	* Virtual function for getting the length of the cell content
	 * @brief By this function we can get the length of the cell, no matter it's type
	 * @return Int value - the width of the cell in decimal places
	*/
	virtual int getCellLength() const;

	/**
	* Virtual function for copying a cell
	 * @brief By this function we can copy one cell to another not in the way to make new object
	 * @return Pointer to the selected cell
	*/
	virtual Cell* copyCell() = 0;

	/**
	* Default virtual destructor
	 * @brief Used to delete the data allocated on the heap ,in our case the content of the cell
	*/
	virtual ~Cell();
};

