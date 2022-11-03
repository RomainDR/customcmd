#pragma once
#include <string>
#include "PathManager.h"

class CommandManager;
class FileUtils;

class Console
{
#pragma region f/p
	std::string name = "";
	CommandManager* cm = nullptr;
	PathManager* pm = PathManager::Instance();
#pragma endregion f/p

#pragma region constructor
public:
	Console() = default;
	Console(std::string _name);
	~Console();
#pragma endregion constructor

#pragma region methods
public:
	void WaitCommand();
	CommandManager* GetCommandManager();
#pragma endregion methods
};

