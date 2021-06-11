#pragma once
#include <iostream>
#include <fstream>
#include <string>
/**
* \class Commands
 * @brief Class Commands representing most of the commands which can be made through the CLI
*/
class Commands
{
protected:
	std::fstream activeFile;/**< Variable to work with file */
	char* activeFilePath;/**< The location of the currently used file */
	bool parser{}; /**< Variable used to check if we can communicate with the CLI */
	bool isFileOpened{}; /**< Variable for checking if a file is actually opened */

	/**
	* Default constructor
	 * @brief This is the default constructor for Commands
	*/
	Commands();

	/**
	* Virtual unction for opening file
	 * @brief With this function we can open file form the selected path
	 * @param fileLocation The location of the file
	 * @return True is the file is opened successfully and false if not
	*/
	virtual bool open(const char* fileLocation);

	/**
	* Virtual function for closing file
	 * @brief With this function we can close a file, if was not closed yet
	*/
	virtual void close();

	/**
	* virtual function for saving a file
	 * @brief With this function we can save the file to the current location
	 * @see saveAs()
	 * @return True is the file is saved successfully and false if not
	*/
	virtual bool save()=0;

	/**
	* New command
	 * @brief With this command you can create an empty table with no file associated with it
	*/
	virtual void newCommand();

	/**
	* virtual function for saving a file to a new location or name
	 * @brief With this function we can save the file to a selected location
	 * @return True is the file is saved successfully and false if not
	*/
	virtual bool saveAs(const char* fileLocation)=0;

	/**
	* Function for exiting the programs
	 * @brief With this function we terminate the program by prompting a save message
	*/
	void exit();

	/**
	* Function help
	 * @brief This function shows the available command supported by the CLI
	*/
	void help();

	/**
	* Function for executing commands
	 * @brief With this function we can execute commands
	 * @param command The command name
	 * @param arguments The arguments of the given command
	 * @return True if the command is executed successful and false if not
	*/
	virtual bool parseRead(const char* command, const char* arguments);

	/**
	* Default virtual destructor
	 * @brief Used to delete the data allocated on the heap ,in our case the content of the location of the file
	*/
	virtual ~Commands();

public:
	/**
	* Function for reading commands
	 * @brief With this function we read commands
	 * @param command The command name
	 * @param arguments The arguments of the given command
	 * @return True if the command is read successful and false if not
	*/
	void parsingFromFile();
};

