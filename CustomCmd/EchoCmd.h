#pragma once
#include "ICommand.h"
class EchoCmd : public ICommand
{
private:
	std::string shortcut = "";
	std::string description = "";
	bool active = true;

public:
	EchoCmd(std::string _shortcut, std::string  _description);


public:	
	virtual std::string GetShortcut() override;
	virtual std::string GetDescription() override;
	virtual void Execute() override;
	virtual void Execute(std::string _args) override;
	virtual void GetHelp() override;

};

