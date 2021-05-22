#pragma once
#include <iostream>
#include <fstream>
#include <string>
class Commands
{
protected:
	std::fstream activeFile;
	bool parser, isFileOpened;

	bool open(const std::string fileLocation);
	void close();
	//virtual void save()=0;
	//virtual void newCommand()=0;
	//virtual void saveAs(const std::string fileLocation)=0;
	void exit();
	//void help();
	bool parseRead(const std::string command, const std::string arguments);
public:
	void parsingFromFile();
};

