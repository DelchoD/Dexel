#pragma once
#include <iostream>
#include <stdlib.h>
#include "CellUtils.h"

/**
* Function for replacing capital letters with small ones
 * @brief With this function we can validate if a symbol is a small or capital letter and if yes we can replace it
 * @param symbol Char to examine
 * @return Char of the lowered symbol if it was needed
 * @see lowerred(const char* _stringToLower)
*/
char converToLower(char symbol);

/**
* Function for lowering a string
 * @brief With this function we can lower a string
 * @param _stringToLower String to lower
 * @return lowered string
 * @see converToLower(char symbol)
*/

std::string lowerred(const char* _stringToLower);
/**
* Function for reading when editing a cell
 * @brief With this function we can edit cell by its reference in the table and the new value
 * @param str String with the reference and the new value
 * @param row Row index of the referenced cell
 * @param column Column index of the referenced cell
 * @param endRef Index in the string after reading the reference
 * @return True if the cell is edited successfully and false if not
*/

bool readForEdit(const char* str, int& row, int& column,int& endRef);
/**
* Function validating symbol as a operator in the terms of the project
 * @brief With this function we can validate if the selected symbol is an operator
 * @param symbol Symbol to examine
 * @return True if the selected symbol is an operator and false if not
*/

bool isOperator(char symbol);
/**
* Function validating symbol as a table column index in the terms of the project
 * @brief With this function we can validate if the selected symbol is a table column index
 * @param symbol Symbol to examine
 * @return True if the selected symbol is a table column index and false if not
*/
bool IsTableRowIndex(char symbol);

/**
* Function validating sating as a number
 * @brief With this function we can validate if the chosen string can be parsed to int or double
 * @param valueToExamine string which we are going to examine
 * @return True if the selected string is a number and false if not
*/
bool isConvertable(const char* valueToExamine);
