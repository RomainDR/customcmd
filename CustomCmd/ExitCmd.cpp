#include "ExitCmd.h"
#include "Utils.h"
ExitCmd::ExitCmd(std::string _shortcut, std::string _description)
{
    shortcut = _shortcut;
    description = _description;
}

std::string ExitCmd::GetShortcut()
{
    return shortcut;
}

std::string ExitCmd::GetDescription()
{
    return description;
}

void ExitCmd::Execute()
{
    exit(0);
}

void ExitCmd::Execute(std::string _args)
{
    try {
        int _exitCode = std::stoi(_args);
        exit(_exitCode);
    }
    catch(std::exception e)
    {
        Utils::Log("[Exception] => " + _args + " is not exit code. Program stop with defaut exit code 0");
        exit(0);
    }
}

void ExitCmd::GetHelp()
{
    std::string _result = description + "\n";
    _result += "Type 'exit' to close the program\n";
    _result += "Type 'exit' [exit code] to close with exit code";
    Utils::Log(_result);
}
