#include "Commands.h"
#include "GeneralUtils.h"
#include "TableCommands.h"
#include <string>
#include <algorithm>

Commands::Commands():activeFilePath(NULL),isFileOpened(false)
{
}

bool Commands::open(const char* fileLocation)
{
	activeFile.open(fileLocation);
	if (activeFile.fail())
	{
		std::cerr << "There is a problem in opening the file, please try again in a few seconds!\n";
		activeFile.clear();
		return false;
	}
	activeFilePath = new char[strlen(fileLocation)];
	strcpy(activeFilePath, fileLocation);
	isFileOpened = true;
	return true;
}

void Commands::close()
{
	if (isFileOpened)
	{
		activeFile.close();
		std::cout << "File is closed successfully\n" << std::endl;
	}
	isFileOpened = false;
	std::cout << "There is problem in opening the file, please try again\n";
}

void Commands::exit()
{
	parser = false;
}

void Commands::help()
{
	std::cout << "Command        Usage\n";
	std::cout << "close          close - closes currently opened file\n";
	std::cout << "open           open <filelocation> - loads the selected file<file>\n";
    std::cout << "save           save - saves the currently open file\n";
	std::cout << "new            new - create new empty file\n";
	std::cout << "saveas         saveas <file> -saves the currently open file in <file> move the program parser to it\n";
    std::cout << "edit           edit <ColumnName><Row number> - prompts for the new value of the cell\n";
	std::cout << "help           help - prints this information\n";
    std::cout << "print          print - prints the information int the current table\n";
    std::cout << "exit           exit - exists the program\n";
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
		this->help();
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
	if (isFileOpened)
	{
		close();
	}
	delete[] activeFilePath;
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
		if ((strcmp(command,"print")!=0)&&(strcmp(command, "help") != 0))
		{
			std::cin.ignore();
		}

		std::cin.getline(arguments,511);
		if (!parseRead(command, arguments))
		{
			std::cout << "The command you have entered is not supported yet, to find commands compatible with this version type help\n";
		}
	}
}
