#pragma once
#include <iostream>
#include <fstream>
#include <string>
class Commands
{
protected:
	std::fstream activeFile;
	bool parser;

	void open(const std::string fileLocation);
	void close();
	void save();
	void newCommand();
	void saveAs(const std::string fileLocation);
	void exit();
	void help();
	bool parseRead(const std::string command, const std::string arguments);
public:
	void parsingFromFile();
};

