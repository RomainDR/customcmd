#include "ClsCmd.h"
#include "Utils.h"
ClsCmd::ClsCmd(std::string _shortcut, std::string _description)
{
    shortcut = _shortcut;
    description = _description;
}


std::string ClsCmd::GetShortcut()
{
    return shortcut;
}


std::string ClsCmd::GetDescription()
{
    return description;
}

void ClsCmd::Execute()
{
    system("cls");
}

void ClsCmd::GetHelp()
{
    Utils::Log("Clear the console");
}

void ClsCmd::Execute(std::string _args)
{
    Utils::Log(description);
}
