#pragma once
#include <iostream>
/**
	 \enum TypeOfCell
	 * Enum with the available types of cells
	 */
enum class TypeOfCell
{
	Unknown = -1,/**< Unknown type when we don't know nothing for the content */
	Integer,/**< Integer type representing an integer type cell */
	Double,/**< Doubler type representing a double type cell */
	String,/**< String type representing a string type cell */
	Formula,/**< Formula type representing a formula type cell */
	Empty/**< Empty type representing an empty cell */
};

/**
* Function for determining a cell type
 * @brief By this function we can determine the type of a cell by given string
 * @param _cellContent The string which we use for identifying
 * @return Object from type TypeOfCell
*/
TypeOfCell findCellType(char* _cellContent);

/**
* Function for validating symbol as a digit
 * @brief With this function we can check if a symbol is a numeric(0-9)
 * @param symbol Char used to examine
 * @return True if the symbol is from numeric type and false if not
*/
bool isDigit(char symbol);

