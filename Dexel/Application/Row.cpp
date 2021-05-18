#include "Row.h"

bool Row::readRow(std::string source, std::string buffer, int* length)
{
	size_t index = 0;
	for (index; source[index]!=',' && source[index] != '\0'; index++)
	{
		buffer[index] = source[index];
	}
	buffer[index] = '\0';
	*length = ++index;

	return source[index] != '\0';
}

Row::Row()
{
}

Row::Row(std::string rowValue)
{
	std::string tempReader = rowValue, tempBuffer;
	int position = 0;
	while (readRow(tempReader, tempBuffer, &position))
	{

	}
}

Row::Row(const Row& rhs)
{
	
}
