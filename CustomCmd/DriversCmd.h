#pragma once
#include "ICommand.h"
class DriversCmd : public ICommand
{
private:
	std::string shortcut = "";
	std::string description = "";
public:
	DriversCmd(std::string _shortcut, std::string _description);

public:
	virtual std::string GetShortcut() override;
	virtual std::string GetDescription() override;
	virtual void Execute() override;
	virtual void GetHelp() override;

	// Hérité via ICommand
	virtual void Execute(std::string _args) override;
};

