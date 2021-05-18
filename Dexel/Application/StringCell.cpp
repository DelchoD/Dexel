#include "StringCell.h"

StringCell::StringCell(std::string _cellContent):Cell(_cellContent)
{
}

Cell* StringCell::copyCell()
{
    return new StringCell(*this);
}
