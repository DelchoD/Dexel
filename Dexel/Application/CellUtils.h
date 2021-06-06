#pragma once
#include <iostream>
enum class TypeOfCell
{
	Unknown=-1,
	Integer,
	Double,
	String,
	Formula,
	Empty
};

TypeOfCell findCellType(const char* _cellContent);
std::string trim(std::string trimmedValue);
int parseInt(char* valueToExamine, int* len=nullptr);
double parseDouble(char* valueToExamine, int* len=nullptr);
bool isDigit(char symbol);

