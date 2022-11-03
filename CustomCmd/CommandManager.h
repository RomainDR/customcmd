#pragma once
#include <vector>
#include <string>

class ICommand;

class CommandManager
{

#pragma region f/p
private:
	std::vector<ICommand*> commands = std::vector<ICommand*>();
#pragma endregion f/p

#pragma region contructor/destructor
public:
	CommandManager();
	~CommandManager();

#pragma endregion contructor/destructor


#pragma region methods
public:
	void LoadCommands();
	std::vector<ICommand*> GetCommands();
	ICommand* GetCommand(std::string _shortcut);
#pragma endregion methods
};

