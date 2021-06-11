#pragma once
#include <vector>
#include "Row.h"
#include "GeneralUtils.h"
#include "CellInterface.h"
#include "TableInterface.h"
/**
* \class Table
 * @brief Class Table used to unite rows created by class Row
*/
class Table : public TableInterface
{
private:
	std::vector<Row> tableRows;/**< Vector storing the information about rows int the table */
	std::vector<int> columnWidths;/**< Vector storing the information about column widths in order they to be properly displayed */

	/**
	* Function for setting the column width
	 * @brief With this function each column width is set to the larges cell
	*/
	void setColumnWidth();
public:
	/**
	* Printing table function
	 * @brief With this function we can print the information stroed in the table
	*/
	void print();

	/**
	* Function for editing a cell
	 * @brief With this function we can edit a cell by given arguments
	 * @param rowIndex The row index of the cell which we are going to edit
	 * @param columnIndex The column index of the cell which we are going to edit
	 * @param newContent The desired content of the cell to edit
	*/
	void edit(int rowIndex,int columnIndex, const char* newContent);

	/**
	* Re staring table function
	 * @brief With this function we can restart the table in order to empty it and prepare it to be ready for the next read
	*/
	void restart();

	/**
	* Function for writing in files
	 * @brief By this function we can save the content of the selected table to a type of fstream stream
	 * @param writer The stream which we are going to use
	*/
	void writeToFile(std::fstream& writer) const;

	/**
	* Function for getting a cell address
	 * @brief With this function we can get the ad?ress of a cell by it's row and column index
	 * @param row The index of the row for our cell
	 * @param col The index of the column for our cell
	 * @see TableInterface class
	 * @return Pointer to the desired cell
	*/
	CellInterface* getCell(int row, int col) const;

	/**
	* Function for reeding from a file
	 * @brief With this function we can read table from a file
	 * @param reader The fstream type stream which we are going to use
	 * @return True if the table is loaded successfully and false if not
	*/
	bool parseFromFile(std::istream& reader); //check this twice

	/**
	* Function for getting the length of a column
	 * @brief With this function we can get the size of each column in order they to be ordered in the print
	 * @param columnIndex The index of each column
	 * @see TableInterface class
	 * @return Int value of the size of the column
	*/
	int getColumnWidth(int columnIndex) const;

	/**
	* Function for getting the row with most cells
	 * @brief With this function we can get the row with most of cells
	 * @return Number of cells of the longest row
	*/
	int getMaximunCellsPerRow() const;

	/**
	* Function for checking if the table is empty
	 * @brief With this function we can check if out table has no content
	 * @return True is there is nothing in the table and false if not
	*/
	bool isEmpty();

	/**
	* Function for resizing the number of rows
	 * @brief With this function we can resize the number of row in order to edit cell outside the current table
	 * @param rowsTotal Number of rows to be at the end
	 * @param columnTotal Number of columns to be at the end
	*/
	void resize(int rowsTotal, int columnTotal);
};

