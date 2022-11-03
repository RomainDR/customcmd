#pragma once
#include <string>
#include <vector>
#include "ICommand.h"
class TimeCmd : public ICommand
{
#pragma region f/p
private:
	std::string shortcut = "";
	std::string description = "";
	std::vector<std::string> lines = std::vector<std::string>();
#pragma endregion f/p
#pragma region constructor
public:
	TimeCmd() = default;
	TimeCmd(std::string _shortcut, std::string _description);
#pragma endregion constructor

#pragma region methods
public:
	virtual std::string GetShortcut() override;
	virtual std::string GetDescription() override;
	virtual void Execute() override;
	virtual void GetHelp() override;
#pragma endregion methods


	// Hérité via ICommand
	virtual void Execute(std::string _args) override;

};

