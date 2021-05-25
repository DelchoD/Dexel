#pragma once
#include "Commands.h"
#include "Table.h"
class TableCommands : public Commands
{
private:
	Table table;

	bool parseRead(const std::string command, const std::string arguments);
	bool open(const std::string fileLocation);
	void save();
	//void newCommand();
	bool saveAs(const std::string fileLocation);
	void edit(const std::string editionParameters);
	void print();

	void CSVWriter(std::fstream& writer);
	bool CSVReader();
};

