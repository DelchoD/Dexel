#pragma once
#include "Commands.h"
#include "Table.h"
/**
* \class TableCommands
 * @brief Class TableCommands representing the commands unique for the project that need to be implemented through the CLI
*/
class TableCommands : public Commands
{
private:
	Table table; /**< Value for storing the table */
	bool isRestarted = false; /**< Value for storing the information if the table was restarted */

	/**
	* Function for executing commands
	 * @brief With this function we can execute commands
	 * @param command The command name
	 * @param arguments The arguments of the given command
	 * @see Commands class
	 * @return True if the command is executed successful and false if not
	*/
	virtual bool parseRead(const char* command, const char* arguments);

	/**
	* Virtual unction for opening file
	 * @brief With this function we can open file form the selected path
	 * @param fileLocation The location of the file
	 * @see Commands class
	 * @return True is the file is opened successfully and false if not
	*/
	virtual bool open(const char* fileLocation);

	/**
	* virtual function for saving a file
	 * @brief With this function we can save the file to the current location
	 * @see saveAs()
	 * @see Commands class
	 * @return True is the file is saved successfully and false if not
	*/
	virtual bool save();

	/**
	* New command
	 * @brief With this command you can create an empty table with no file associated with it
	*/
	virtual void newCommand();

	/**
	* Virtual function for saving a file to a new location or name
	 * @brief With this function we can save the file to a selected location
	 * @see Commands class
	 * @return True is the file is saved successfully and false if not
	*/
	virtual bool saveAs(const char* fileLocation);

	/**
	* Fucntion for editing a cell
	 * @brief With this function we can edit a cell by given new value
	 * @param editionParameters Value to insert
	*/
	virtual void edit(const char* editionParameters);

	/**
	* Virtual function for closing file
	 * @brief With this function we can close a file, if was not closed yet
	*/
	virtual void close();

	/**
	* Printing function
	 * @brief With this function we can print the table to the console
	*/
	void print();

	/**
	* Function for writing a table to a fstream type stream
	 * @brief With this function we can save the table to a file
	 * @param writer The stream which we are going to use
	*/
	void CSVWriter(std::fstream& writer);

	/**
	* Function for reading a table from a file
	 * @brief With this function we can read a table from the currently opened file
	 * @return True if the table was read successfully and false if not
	*/
	bool CSVReader();
public:
};

