#include "EchoCmd.h"
#include "Utils.h"

EchoCmd::EchoCmd(std::string _shortcut, std::string _description)
{
    shortcut = _shortcut;
    description = _description;
}

std::string EchoCmd::GetShortcut()
{
    return shortcut;
}

std::string EchoCmd::GetDescription()
{
    return description;
}

void EchoCmd::Execute()
{
    std::string _active = active ? "Yes" : "No";
    std::string _result = "Echo enabled: " + _active + '\n';
    _result += "Type echo [ON | OFF] to change status. \n";
    Utils::Log(_result);
}

void EchoCmd::Execute(std::string _args)
{    
    std::string _str = Utils::ToLower(_args);
    if (_str == "on" || _str == "off")
    {
        active = _str == "on";
        std::string _active = active ? "On" : "Off";
        Utils::Log("Echo has been set: " + _active);
    }
    else if (active)
        Utils::Log(_args);
}

void EchoCmd::GetHelp()
{
    Utils::Log("Echo [ON|OFF] to activate/desactivate echo command\nEcho [message] to send message in console.\n\nEcho without args to show echo status");
}
