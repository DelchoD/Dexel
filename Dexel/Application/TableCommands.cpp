#include "TableCommands.h"
#include "GeneralUtils.h"

bool TableCommands::parseRead(char* command, const char* arguments)
{
	if (strcmp(command,"print")==0)
	{
		std::cout << "Hello";
		this->print();
	}
	else if (strcmp(command, "edit")==0)
	{
		this->edit(arguments);
	}
	else
	{
		return Commands::parseRead(command, arguments);
	}
	return true;

}

bool TableCommands::open(const char* fileLocation)
{
	if (!Commands::open(fileLocation))
	{
		return false;
	}
	return CSVReader();
}

bool TableCommands::save()
{
	activeFile.close();
	if (!saveAs(activeFilePath)) 
	{
		return false;
	}
	return open(activeFilePath);
	CSVWriter(activeFile);
}

bool TableCommands::saveAs(const char* fileLocation)
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

void TableCommands::edit(const char* editionParameters)
{
	int row = 0, col = 0, endFirst = 0, endSecond = 0;
	if (!readForEdit(editionParameters, ' ', row, &endFirst) || !readForEdit(editionParameters + endFirst, ' ', col, &endSecond) && row >= 0 && col >= 0) 
	{
		std::cout << "Something is wrong with the input data" << std::endl;
	}
	for (endSecond; editionParameters[endFirst+endSecond] == ' '; ++endSecond);
	const char* newContent = editionParameters+endFirst + endSecond;
	table.edit(row-1, col-1, newContent);
}

void TableCommands::close()
{
	Commands::close();
	table.restart();
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
