#pragma once
#include <iostream>
#include <fstream>
#include <string>
class Commands
{
protected:
	std::fstream activeFile;
	char* activeFilePath;
	bool parser, isFileOpened;

	bool open(const char* fileLocation);
	void close();
	virtual bool save()=0;
	//virtual void newCommand()=0;
	virtual bool saveAs(const char* fileLocation)=0;
	void exit();
	//void help();
	bool parseRead(const char* command, const char* arguments);
	virtual ~Commands();
public:
	void parsingFromFile();
};

