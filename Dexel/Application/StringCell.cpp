#include "StringCell.h"
#include "GeneralUtils.h"
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
    char temp[512]{};
    if (*cellContent)
    {
        strcpy(temp, cellContent);
        size_t i = 0;
        for (i; temp[i] != '\0'; i++)
        {
            temp[i] = temp[i + 1];
        }
        temp[i - 2] = '\0';
    }
    
    return (isConvertable(temp)) ? atof(temp) : 0;
}

Cell* StringCell::copyCell()
{
    return new StringCell(*this);
}
