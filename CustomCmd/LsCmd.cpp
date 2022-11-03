#include "LsCmd.h"
#include "Utils.h"
#include <filesystem>
#include "PathManager.h"

LsCmd::LsCmd(std::string _shortcut, std::string _description)
{
    shortcut = _shortcut;
    description = _description;
}

std::string LsCmd::GetShortcut()
{
    return shortcut;
}

std::string LsCmd::GetDescription()
{
    return description;
}

void LsCmd::Execute()
{
    std::vector<std::string> files = std::vector<std::string>();
    std::string path = PathManager::Instance()->GetPath();
    for (const std::filesystem::directory_entry _directory : std::filesystem::directory_iterator(path))
    {
        std::string _path = _directory.path().string();
        Utils::Replace(_path, '\\', '/');
        std::string _fileName = _path.substr(_path.find_last_of('/')+1, _path.npos);
        files.push_back(_fileName);
    }
    size_t _size = files.size();
    std::string lines = "";
    for (int i = 0; i < _size; i++)
    {
        lines += files[i] + "\n";
    }
    Utils::Log(lines);
}

void LsCmd::Execute(std::string _args)
{
    return GetHelp();
}

void LsCmd::GetHelp()
{
    std::string _result = "Show all files and folder in current directory";
    Utils::Log(_result);
}
