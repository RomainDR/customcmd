#include "CdCmd.h"
#include "Utils.h"
#include "PathManager.h"
CdCmd::CdCmd(std::string _shortcut, std::string _description)
{
	shortcut = _shortcut;
	description = _description;
}

std::string CdCmd::GetShortcut()
{
	return shortcut;
}
std::string CdCmd::GetDescription()
{
	return description;
}

void CdCmd::Execute()
{
	PathManager* pm = PathManager::Instance();
	Utils::Log(pm->GetPath());
}

void CdCmd::Execute(std::string _args)
{
	PathManager* pm = PathManager::Instance();
	std::string path = pm->GetPath();
	if (_args == "..")
	{
		std::string _newPath = path.substr(0, path.find_last_of('/'));
		pm->SetPath(_newPath);
		return;
	}
	if (pm->StartInDrivers(_args)) {
		path = _args;
		Utils::Replace(path, '\\', '/');
		Utils::Replace(path, std::tolower(path[0]), std::toupper(path[0]));
		pm->SetPath(path);
		return;
		std::vector<std::string> parts = Utils::Split(_args, '/');
		std::string _str = path;
		int num = 0;
		size_t _size = parts.size();
		while (num < _size && pm->ExistPath(_str + "/" + parts[num]))
		{
			_str += "/" + parts[num];
			num++;
		}
		if (num != parts.size()) {
			Utils::Log("Path not exist.");
			return;
		}
		pm->SetPath(_str);
	}
}

void CdCmd::GetHelp()
{
	std::string _result = "Change directory file.\n";
	_result += "cd [path] to access on other directory\n";
	_result += "cd .. to access parent directory\n";
	Utils::Log(_result);

}
