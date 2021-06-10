#include "StringCell.h"
#include <fstream>
StringCell::StringCell(const char* _cellContent):Cell(_cellContent)
{
}

void StringCell::writeToFile(std::fstream& writer)
{
    writer << cellContent;
}

void StringCell::print()
{
    std::cout << cellContent;
}

double StringCell::examine()const
{
    return 0;
}

Cell* StringCell::copyCell()
{
    return new StringCell(*this);
}
