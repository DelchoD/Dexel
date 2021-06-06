#include "Commands.h"
#include "GeneralUtils.h"
#include <string>
#include <algorithm>

bool Commands::open(const char* fileLocation)
{
	activeFile.open(fileLocation);
	if (activeFile.fail())
	{
		std::cerr << "There is a problem in opening the file, please try again in a few seconds!";
		activeFile.clear();
		return false;
	}
	activeFilePath = new char[strlen(fileLocation)];
	strcpy(activeFilePath, fileLocation);
	return true;
}

void Commands::close()
{
	if (!activeFile.is_open())
	{
		//throw an exception
	}
	activeFile.close();
}

void Commands::exit()
{
	parser = false;
}

bool Commands::parseRead(const char* command, const char* arguments)
{
	//switch can be used with integral or enum types
	if (strcmp(command,"open")==0)
	{
		this->open(arguments);
	}
	else if (strcmp(command, "exit") == 0)
	{
		this->exit();
	}
	else if (strcmp(command, "close") == 0)
	{
		this->close();
	}
	else if (strcmp(command, "help") == 0)
	{
		//this->help();
	}
	else if (strcmp(command, "save") == 0)
	{
		//this->save();
	}
	else if (strcmp(command, "saveas") == 0)
	{
		//this->saveAs(arguments);
	}
	else
	{
		return false;
	}
	return true;
}

Commands::~Commands()
{
	delete[] activeFilePath;
	close();
}

void Commands::parsingFromFile()
{
	parser = true;
	char command[6];
	char arguments[512];
	while (parser)
	{
		std::cout << "Please enter your command: ";
		std::cin >> command;
		std::cin.getline(arguments,511);
		if (!parseRead(command, arguments))
		{
			std::cout << "The command you have entered is not supported yet, to find commands compatible with this version type help\n";
		}
	}
}
