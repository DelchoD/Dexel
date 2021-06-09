#pragma once
#include <iostream>
/**
	 \enum TypeOfCell
	 * Enum with the available types of cells
	 */
enum class TypeOfCell
{
	Unknown=-1,/**< Unknown type when we don't know nothing for the content */
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
TypeOfCell findCellType(const char* _cellContent);
/**
* Function for removing the white spaces
 * @brief With this function we can remove the whitespaces at the end int the begging
 * @param trimmedValue 
 * @return 
*/
std::string trim(std::string trimmedValue);
/**
* Function for reading int cell
 * @brief By this function we can read int from a string
 * @param valueToExamine String which we are going to use for parsing
 * @param len Length of the string used after to jump ahead
 * @return An int value of the sting in the valueToExamine
*/
int parseInt(char* valueToExamine, int* len=nullptr);
/**
* Function for reading double cell
 * @brief By this function we can read double from a string
 * @param valueToExamine String which we are going to use for parsing
 * @param len Length of the string used after to jump ahead
 * @return An Double value of the sting in the valueToExamine
*/
double parseDouble(char* valueToExamine, int* len=nullptr);
/**
* Function for validating symbol as a digit
 * @brief With this function we can check if a symbol is a numeric(0-9)
 * @param symbol Char used to examine
 * @return True if the symbol is from numeric type and false if not
*/
bool isDigit(char symbol);

