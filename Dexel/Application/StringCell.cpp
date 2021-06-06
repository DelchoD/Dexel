#include "StringCell.h"

StringCell::StringCell(const char* _cellContent):Cell(_cellContent)
{
}

//void StringCell::writeToFile(std::fstream& writer)
//{
//}
//
//void StringCell::print()
//{
//}

Cell* StringCell::copyCell()
{
    return new StringCell(*this);
}
