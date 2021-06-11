#include "TableCommands.h"
#include "GeneralUtils.h"

bool TableCommands::parseRead(const char* command, const char* arguments)
{

	if (strcmp(command,"print")==0)
	{
		if (!table.isEmpty())
		{
			this->print();
		}
		else
		{
			std::cout << "There is no table loaded in the program\n";
		}
	}
	else if (strcmp(command, "edit")==0)
	{

		this->edit(arguments);
	}
	else if (strcmp(command, "new") == 0)
	{
		this->newCommand();
	}
	else
	{
		return Commands::parseRead(command, arguments);
	}
	return true;

}

bool TableCommands::open(const char* fileLocation)
{
	if (!table.isEmpty())
	{
		std::cout << "There is another file opened, do you want to save the changes up to the moment?\n";
		std::cout << "Enter yes or no: ";
		char answer[5]{};
		std::cin >> answer;
		if (strcmp(answer, "yes") == 0)
		{
			this->saveAs(activeFilePath);
			this->close();
		}
		else if (strcmp(answer, "no") == 0)
		{
			this->close();
		}
	}
	if (!Commands::open(fileLocation))
	{
		return false;
	}
	if (!CSVReader())
	{
		//std::cout << "There is a problem with reading the file\n";
		return false;
	}
	if (!isRestarted)
	{
		std::cout << "Successfully opened " << fileLocation << "\n";
	}
	activeFile.close();
	//return CSVReader();
}

bool TableCommands::save()
{
	//activeFile.close();
	if (!saveAs(activeFilePath)) 
	{
		return false;
	}
	table.restart();
	isRestarted = true;
	return open(activeFilePath);
}

void TableCommands::newCommand()
{
	return table.restart();
}

bool TableCommands::saveAs(const char* fileLocation)
{
	std::fstream tempFile;
	tempFile.open(fileLocation, std::ios::trunc | std::ios::out);

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
	catch (const std::out_of_range&)
	{
		table.resize(row, col);
		table.edit(row - 1, col - 1, newContent);
		std::cout << "The cell can not be edited please check the row and column indexes and try again\n";
		//Commands::parsingFromFile();
	}
	catch (const std::invalid_argument& e)
	{
		std::cout << "The value you want to change is not supported\n";
		return;
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
