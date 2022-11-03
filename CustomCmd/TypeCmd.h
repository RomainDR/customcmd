#pragma once
#include "ICommand.h"
#include "Console.h"
#include <fstream>

class TypeCmd : public ICommand
{
private:
	std::string shortcut = "";
	std::string description = "";
	std::ifstream stream = std::ifstream();

public:
	TypeCmd() = default;
	TypeCmd(std::string _shortcut, std::string _description);

public:
	virtual std::string GetShortcut() override;
	virtual std::string GetDescription() override;
	virtual void Execute() override;
	virtual void Execute(std::string _args) override;
	virtual void GetHelp() override;
};

