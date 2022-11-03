#pragma once
#include "ICommand.h"
class CdCmd : public ICommand
{
private:
	std::string shortcut = "";
	std::string description = "";
public:
	CdCmd(std::string _shortcut, std::string _description);


public:
	virtual std::string GetDescription() override;
	virtual void Execute() override;
	virtual void Execute(std::string _args) override;
	virtual void GetHelp() override;
	virtual std::string GetShortcut() override;
};

