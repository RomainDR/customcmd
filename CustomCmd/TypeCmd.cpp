#include "TypeCmd.h"
#include "Utils.h"
#include "PathManager.h"
#include <vector>

TypeCmd::TypeCmd(std::string _shortcut, std::string _description)
{
    shortcut = _shortcut;
    description = _description;
}
std::string TypeCmd::GetShortcut()
{
    return shortcut;
}

std::string TypeCmd::GetDescription()
{
    return description;
}

void TypeCmd::Execute()
{
    GetHelp();
}

void TypeCmd::Execute(std::string _args)
{
    PathManager* pm = PathManager::Instance();
    std::string path = pm->GetPath();

    if (pm->IsFullPath(_args))
        path = pm->GetPath(_args);

    std::string fileName = _args.substr(path.size() +1, _args.npos);
    std::string fileWithoutExtension = Utils::FileWithoutExtension(fileName);

    if (!pm->Exist(fileWithoutExtension, path)) {
        Utils::Log("File not exist.");
        return;
    }
    stream = std::ifstream(path + "/" + fileWithoutExtension + ".txt");
    std::vector<std::string> lines = std::vector<std::string>();
    std::string _str = "";
    while (std::getline(stream, _str))
        lines.push_back(_str);

    size_t _size = lines.size();
    for (int i = 0; i < _size; i++)
        Utils::Log(lines[i]);
}

void TypeCmd::GetHelp()
{
    std::string _result = "Type the name of the file to read, or the file path.\n";
    _result += "Example:\n";
    _result += "type 'test.txt' => showing all line in 'test.txt'\n";
    _result += "type 'c:/T/test' => showing all line in 'test.txt' in folder 'c:/T/'";
    Utils::Log(_result);

}
