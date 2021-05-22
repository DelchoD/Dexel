#include "Commands.h"
#include "GeneralUtils.h"
#include <string>
#include <algorithm>

bool Commands::open(const std::string fileLocation)
{
	activeFile.open(fileLocation);
	if (activeFile.fail())
	{
		std::cerr << "There is a problem in opening the file, please try again in a few seconds!";
		activeFile.clear();
		return false;
	}
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
		//this->help();
	}
	else if (lowerred(command) == "save")
	{
		//this->save();
	}
	else if (lowerred(command) == "saveas")
	{
		//this->saveAs(arguments);
	}
	else
	{
		return false;
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
		if (!parseRead(command, arguments))
		{
			std::cout << "The command you have entered is not supported yet, to find commands compatible with this version type help";
		}
		
		//parseRead(temp);
	}
}
