#pragma once
class CellInterface
{
public:
	virtual double examine() const = 0;
	virtual int getCellLength() const=0;
};

