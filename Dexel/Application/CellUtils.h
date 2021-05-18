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

TypeOfCell findCellType(std::string _cellContent);
std::string trim(std::string trimmedValue);
int parseInt(std::string valueToExamine);
double parseDouble(std::string valueToExamine);
bool isDigit(char symbol);

