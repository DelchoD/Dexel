#include "TableCommands.h"
#include "GeneralUtils.h"

bool TableCommands::parseRead(const char* command, const char* arguments)
{

	if (strcmp(command,"print")==0)
	{
		if (!activeFile.is_open())
		{
			std::cout << "There is no file opened, please open one\n";
			return true;
		}
		this->print();
	}
	else if (strcmp(command, "edit")==0)
	{
		if (!activeFile.is_open())
		{
			std::cout << "There is no file opened, please open one\n";
			return true;
		}
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
	if (!isRestarted)
	{
		std::cout << "Successfully opened " << fileLocation << "\n";
	}
	if (!CSVReader())
	{
		std::cout << "There is a problem with reading the file\n";
	}
	//return CSVReader();
}

bool TableCommands::save()
{
	activeFile.close();
	if (!saveAs(activeFilePath)) 
	{
		return false;
	}
	table.restart();
	isRestarted = true;
	return open(activeFilePath);
}

bool TableCommands::saveAs(const char* fileLocation)
{
	std::fstream tempFile;
	if (strcmp(fileLocation, activeFilePath)==0)
	{
		tempFile.open(fileLocation, std::ios::trunc | std::ios::out);
	}
	else
	{
		tempFile.open(fileLocation, std::ios::trunc | std::ios::out);
	}

	if (tempFile.fail())
	{
		std::cout << "There was an error in saving the file, please try again in a couple of seconds\n";
		tempFile.clear();
		return false;
	}

	CSVWriter(tempFile);
	tempFile.close();
	std::cout << "The table is successfully saved to " << fileLocation<<"\n";
	return true;
}

void TableCommands::edit(const char* editionParameters)
{
	int row = 0, col = 0, endOfReference = 0;
	bool isSuccessfull = false;
	if (!readForEdit(editionParameters, row, col, endOfReference) && row >= 0 && col >= 0)
	{
		std::cout << "Something is wrong with the input data" << std::endl;
	}

	for (endOfReference; editionParameters[endOfReference] == ' '; ++endOfReference);
	const char* newContent = editionParameters + endOfReference;

	try
	{
		table.edit(row - 1, col - 1, newContent);
		std::cout << "The selected cell is changed successfully to " << newContent << "\n" << std::endl;
		isSuccessfull = true;
	}
	catch (const std::out_of_range& e)
	{
		std::cout << "The cell can not be edited please check the row and column indexes and try again\n";
		Commands::parsingFromFile();
	}
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
