#pragma once
#include <iostream>
#include <vector>
#include "Cell.h"
class Table;
/**
* \class Row
 * @brief Class Row represents a single row of cells of type Cell in a a table
*/
class Row
{
protected:
	std::vector<Cell*> cellsPerRow;/**< Vector storing the information about all cells per row */
	TableInterface* transfer;/**< Variable with witch we can index the row for following search */
	/**
	* Function for reading a single row
	 * @brief With this function we can convert string into many cells then group them in a row
	 * @param source String from which we are going to write
	 * @param buffer Variable for storing the cell content of a single cell
	 * @param length The lenght of the read string up to the moment
	 * @return True if the row is read successfully and false if not
	*/
	bool readRow(const char *source, char *buffer,int* length=nullptr)const;
	/**
	* Function for creating single cell
	 * @brief With this function we can create single cell form given string
	 * @param cellCont String used to initialize the cell
	 * @return Pointer to the newly created cell
	*/
	Cell* createCell(const char* cellCont)const;
public:
	/**
	* Row default constructor
	 * @brief This is the default constructor for Row
	*/
	Row();
	/**
	* Row constructor with two parameters
	 * @brief With this constructor we can initialize a new row with given content and table associated with this row
	 * @param rowValue The value of the row we are going to initialize
	 * @param _transfer The table which is associated with this row
	*/
	Row(char *rowValue, TableInterface* _transfer);
	/**
	* Row copy constructor
	 * @brief This is the default copy constructor for Row
	 * @param rhs Object form which to make Row
	*/
	Row(const Row& rhs);
	/**
	* Row default copy assignment operator
	 * @brief This is the default copy assignment operator for Row
	 * @param rhs Object form which to make Row
	 * @return New object from class Row with content identical to rhs
	*/
	Row& operator=(const Row& rhs);
	/**
	* Default destructor
	 * @brief Used to delete the data allocated on the heap ,in our case the content of the vector storing information about the cells
	*/
	~Row();
	/**
	* Function for getting the index of a cell
	 * @brief With this function we can get the information of a cell with given column index
	 * @param columnIndex Index used for searching
	 * @return Pointer to the selected cell
	*/
	Cell* getCell(int columnIndex) const;
	/**
	* Function for printing a single row
	 * @brief By this function we can print the content of a single row to the default std::cout stream
	*/
	void print()const;
	/**
	* Function for counting all cells from a row
	 * @brief With this function we can get number of cell per the row in int type
	 * @return Number of cells per row
	*/
	int getNumberOfCellsPerRow() const;
	/**
	* Function for writing in files
	 * @brief By this function we can save the content of the selected row to a type of fstream stream
	 * @param writer The stream which we are going to use
	*/
	void writeToFile(std::fstream& writer)const;
	/**
	* Function for setting a cell value
	 * @brief With this function we can set a cell a different value
	 * @param columnIndex Column index of the cell which we are going to edit
	 * @param _cellEditedContent New content of the selected cell 
	*/
	void setCell(int columnIndex, const char *_cellEditedContent);
	void resize(int columnTotal);
	TableInterface* getTransfer();
	void setTransfer(TableInterface* rhs);
};

