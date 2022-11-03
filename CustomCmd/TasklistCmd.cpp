#include "TasklistCmd.h"
#include "Utils.h"

TasklistCmd::TasklistCmd(std::string _shortcut, std::string _description)
{
    shortcut = _shortcut;
    description = _description;
}

std::string TasklistCmd::GetShortcut()
{
    return shortcut;
}

std::string TasklistCmd::GetDescription()
{
    return description;
}

void TasklistCmd::Execute()
{
    system("tasklist");
}

void TasklistCmd::Execute(std::string _args)
{
    Utils::Log(description);
}

void TasklistCmd::GetHelp()
{
    std::string _result = "Shows all processes the computer is currently running";
    Utils::Log(_result);
}
