#pragma once
#include "ICommand.h"
#include <filesystem>

class TreeCmd : public ICommand
{
private:
	std::string shortcut = "";
	std::string description = "";
public:
	TreeCmd() = default;
	TreeCmd(std::string _shortcut, std::string _description);


private:
	void DisplayDirectory(std::string& _path, int _numberSub);
public:
	virtual std::string GetShortcut() override;
	virtual std::string GetDescription() override;
	virtual void Execute() override;
	virtual void Execute(std::string _args) override;
	virtual void GetHelp() override;
};

