#include "TableCommands.h"
#include "GeneralUtils.h"

bool TableCommands::parseRead(const std::string command, const std::string arguments)
{
	if (lowerred(command) == "print")
	{
		this->print();
	}
	else if (lowerred(command) == "edit")
	{
		this->edit(arguments);
	}
	else
	{
		return Commands::parseRead(command, arguments);
	}
	return true;
}

bool TableCommands::open(const std::string fileLocation)
{
	if (Commands::open(fileLocation))
	{
		return false;
	}
	return CSVReader();
}

void TableCommands::save()
{
	CSVWriter(activeFile);
}

bool TableCommands::saveAs(const std::string fileLocation)
{
	std::fstream tempFile;
	tempFile.open(fileLocation, std::ios::trunc | std::ios::out);
	if (tempFile.fail())
	{
		std::cout << "There was an error in saving the file, please try again in a couple of seconds";
		tempFile.clear();
		return false;
	}
	CSVWriter(tempFile);
	tempFile.close();
	return true;
}

void TableCommands::edit(const std::string editionParameters)
{
	const std::string temp = editionParameters;
}

void TableCommands::print()
{
	table.print();
}

void TableCommands::CSVWriter(std::fstream& writer)
{
	table.writeToFile(writer);
}

bool TableCommands::CSVReader()
{
	return table.parseFromFile(activeFile);
}
