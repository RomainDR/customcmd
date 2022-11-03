#include "DriversCmd.h"
#include "Utils.h"
#include <vector>
#include "shlobj_core.h"
DriversCmd::DriversCmd(std::string _shortcut, std::string _description)
{
    shortcut = _shortcut;
    description = _description;
}

std::string DriversCmd::GetShortcut()
{
    return shortcut;
}

std::string DriversCmd::GetDescription()
{
    return description;
}

void DriversCmd::Execute()
{
    Utils::Log("Drivers: ");
    std::vector<std::string> arrayOfDrives = std::vector<std::string>();
    char* szDrives = new char[MAX_PATH];
    if (GetLogicalDriveStringsA(MAX_PATH, szDrives)) 
    {
        Utils::Log(szDrives[7] + "");
        size_t _size = sizeof(szDrives);
        for (int i = 0; i < _size; i+=4)
        {
            std::string driver = &szDrives[i];
            Utils::Log(driver);
        }
    }    
}

void DriversCmd::GetHelp()
{
    Utils::Log("Display all drives connected on computer.");
}

void DriversCmd::Execute(std::string _args)
{
    Utils::Log(description);
}
