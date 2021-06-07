#pragma once
#include "Commands.h"
#include "Table.h"
class TableCommands : public Commands
{
private:
	Table table;

	virtual bool parseRead(const char* command, const char* arguments);
	virtual bool open(const char* fileLocation);
	virtual bool save();
	//void newCommand();
	virtual bool saveAs(const char* fileLocation);
	virtual void edit(const char* editionParameters);
	virtual void close();
	void print();

	void CSVWriter(std::fstream& writer);
	bool CSVReader();
};

