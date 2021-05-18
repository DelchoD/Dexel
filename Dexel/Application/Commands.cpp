#include "Commands.h"
#include "GeneralUtils.h"
#include <string>
#include <algorithm>

void Commands::open(const std::string fileLocation)
{
	activeFile.open(fileLocation);
	if (activeFile.fail())
	{
		std::cerr << "There is a problem in opening the file, please try again in a few seconds!";
		activeFile.clear();
	}
	else
	{
		activeFile.open(fileLocation);
	}
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

bool Commands::parseRead(const std::string command, const std::string arguments)
{
	//switch can be used with integral or enum types
	if (lowerred(command) =="open")
	{
		this->open(arguments);
	}
	else if (lowerred(command) == "exit")
	{
		this->exit();
	}
	else if (lowerred(command) == "close")
	{
		this->close();
	}
	else if (lowerred(command) == "help")
	{
		this->help();
	}
	else if (lowerred(command) == "save")
	{
		this->save();
	}
	else if (lowerred(command) == "savas")
	{
		this->saveAs(arguments);
	}
	return true;
}

void Commands::parsingFromFile()
{
	std::string command,arguments;
	while (parser)
	{
		std::cin >> command;
		std::getline(std::cin, arguments);
		parseRead(command, arguments);
		//parseRead(temp);
	}
}
