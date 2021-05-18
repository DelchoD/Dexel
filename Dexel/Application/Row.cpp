#include "Row.h"

Row::Row()
{
}

Row::Row(const Row& rhs)
{
	cellsPerRow = rhs.cellsPerRow;
	cellsPerRow.reserve(rhs.cellsPerRow.size());
	for (auto const &cprt:rhs.cellsPerRow)
	{
		cellsPerRow.emplace_back(cprt->copyCell());
	}
}
