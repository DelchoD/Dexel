#pragma once
#include "Commands.h"
#include "Table.h"
class TableCommands : public Commands
{
private:
	Table table;

	bool parseRead(char* command, const char* arguments);
	bool open(const char* fileLocation);
	bool save();
	//void newCommand();
	bool saveAs(const char* fileLocation);
	void edit(const char* editionParameters);
	virtual void close();
	void print();

	void CSVWriter(std::fstream& writer);
	bool CSVReader();
};

