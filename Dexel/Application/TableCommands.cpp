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
	int row = 0, col = 0, endFirst = 0, endSecond = 0;
	if (!readForEdit(editionParameters, ' ', row, &endFirst) || !readForEdit(editionParameters + std::to_string(endFirst), ' ', col, &endSecond)
		&& row >= 0 && col >= 0) 
	{
		std::cout << "Something is wrong with the input data" << std::endl;
	}
	for (endSecond; editionParameters[endSecond] == ' '; ++endSecond);
	const std::string newContent = editionParameters+std::to_string(endFirst) + std::to_string(endSecond);
	table.edit(row, col, newContent);
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
