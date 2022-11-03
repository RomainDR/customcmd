#pragma once
#include <string>
#include "Object.h"
class ICommand : public Object
{
public:
	virtual std::string GetShortcut() = 0;
	virtual std::string GetDescription() = 0;
	virtual void Execute() = 0;
	virtual void Execute(std::string _args) = 0;
	virtual void GetHelp() = 0;
};