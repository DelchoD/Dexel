#pragma once
#include <iostream>
#include "CellUtils.h"
char converToLower(char symbol);
const char* lowerred(const char* _stringToLower);
bool readForEdit(const char* str, char endSym, int& intHolder, int* lengthRead = nullptr);
bool isOperator(char symbol);
bool IsTableRowIndex(char symbol);
