#pragma once
#include <iostream>
#include "CellUtils.h"
char converToLower(char symbol);
const char* lowerred(const char* _stringToLower);
bool readForEdit(const char* str, int& row, int& column,int& endRef);
bool isOperator(char symbol);
bool IsTableRowIndex(char symbol);
bool IsNumber(char symbol);
