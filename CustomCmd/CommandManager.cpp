#include "CommandManager.h"
#include "TimeCmd.h"
#include "ClsCmd.h"
#include "ICommand.h"
#include "DriversCmd.h"
#include "EchoCmd.h"
#include "ExitCmd.h"
#include "TasklistCmd.h"
#include "TypeCmd.h"
#include "CdCmd.h"
#include "LsCmd.h"
#include "TreeCmd.h"


#include "Utils.h"


CommandManager::CommandManager()
{
	LoadCommands();
}

CommandManager::~CommandManager()
{
	commands.clear();
}

void CommandManager::LoadCommands()
{
	commands.push_back(new TimeCmd("time", "Get current time of system"));
	commands.push_back(new ClsCmd("cls", "Clear the console"));
	commands.push_back(new DriversCmd("drivers", "Display all drives connect on computer"));
	commands.push_back(new EchoCmd("echo", "Show message on console"));
	commands.push_back(new ExitCmd("exit", "Exit the program with exit code"));
	commands.push_back(new TasklistCmd("tasklist", "Displays all processes in use"));
	commands.push_back(new TypeCmd("type", "Display all lines in file"));
	commands.push_back(new CdCmd("cd", "Change directory folder"));
	commands.push_back(new TreeCmd("tree", "show all folders and files from the root of the path"));
	commands.push_back(new LsCmd("ls", "show all files in current directory"));
}

std::vector<ICommand*> CommandManager::GetCommands()
{
	return commands;
}


ICommand* CommandManager::GetCommand(std::string _shortcut)
{
	size_t _size = commands.size();
	for (int i = 0; i < _size; i++)
	{
		if (commands[i]->GetShortcut() == _shortcut)
			return commands[i];
	}
	return nullptr;
}

