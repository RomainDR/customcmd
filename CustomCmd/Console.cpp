#include "Console.h"
#include "Utils.h"
#include "CommandManager.h"
#include "ICommand.h"

Console::Console(std::string _name)
{
	cm = new CommandManager();
	Utils::ChangeTitle(_name);
	WaitCommand();
}

Console::~Console()
{
	delete cm;
}

void Console::WaitCommand()
{
	std::string _choice = Utils::UserChoice<std::string>(pm->GetPath() == "" ? pm->GetPathUser() : pm->GetPath() + ">");
	std::vector<std::string> args = Utils::Split(_choice, ' ');
	

	if (args[0] == "help")
	{		
		if (args.size() == 2)
		{
			ICommand* _cmd = cm->GetCommand(args[1]);
			if (_cmd != nullptr)
				_cmd->GetHelp();
			else
				Utils::Log("Error, no help for \"" + args[1] + "\" command.");
		}
		else {
			Utils::Log(std::string(50, '-'));
			size_t _size = cm->GetCommands().size();
			for (int i = 0; i < _size; i++)
			{
				ICommand* _ic = cm->GetCommands()[i];
				Utils::Log("\t" + _ic->GetShortcut() + "\t\t" + _ic->GetDescription());
			}
			Utils::Log(std::string(50, '-'));
		}
	}	
	else if (cm->GetCommand(args[0]) != nullptr)
	{
		ICommand* _cmd = cm->GetCommand(args[0]);
		if (args.size() == 2)
			_cmd->Execute(args[1]);
		else
			_cmd->Execute();
	}
	else
	{
		Utils::Log("Error, command \"" + _choice + "\" unknown.");
	}
	std::cout << std::endl;
	args.clear();
	WaitCommand();
}

CommandManager* Console::GetCommandManager()
{
	return cm;
}

