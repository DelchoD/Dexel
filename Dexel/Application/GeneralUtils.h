#pragma once
#include <iostream>
#include "CellUtils.h"
char converToLower(char symbol);
std::string lowerred(std::string stringToLower);
bool readForEdit(const std::string str, char endSym, int& intHolder, int* lengthRead = nullptr);

