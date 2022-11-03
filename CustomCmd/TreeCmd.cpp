#include "TreeCmd.h"
#include "Utils.h"
#include "PathManager.h"

TreeCmd::TreeCmd(std::string _shortcut, std::string _description)
{
	shortcut = _shortcut;
	description = _description;
}

void TreeCmd::DisplayDirectory(std::string& _path, int _numberSub)
{
	for (const std::filesystem::directory_entry _directory : std::filesystem::directory_iterator(_path))
	{
		if (_directory.is_directory())
		{
			
			std::string _path = _directory.path().string();
			Utils::Replace(_path, '\\', '/');
			std::string _fileName = _path.substr(_path.find_last_of('/') +1, _path.npos);
			std::string _str = std::string(_numberSub, '\t');
			_str += "--";
			_str += _fileName + "\n";
			_numberSub++;
			_str += std::string(_numberSub, '\t');
			_str += "|";
			Utils::Log(_str);
			DisplayDirectory(_path, _numberSub);
		}
	}
}

std::string TreeCmd::GetShortcut()
{
	return shortcut;
}

std::string TreeCmd::GetDescription()
{
	return description;
}

void TreeCmd::Execute()
{
	std::string _basePath = PathManager::Instance()->GetPath();
	int number = 0;
	DisplayDirectory(_basePath, number);
	/*
			std::string path = _file.path().string();
			Utils::Replace(path, '\\', '/');
			int numberOfDirectory = Utils::CountChar(path, '/');
			std::string fileName = path.substr(path.find_last_of('/'), path.npos);
			std::string _str = std::string(numberOfDirectory, '\t');
			_str += fileName;
			Utils::Log(_str);*/
}

void TreeCmd::Execute(std::string _args)
{
	GetHelp();
}

void TreeCmd::GetHelp()
{
	std::string _result = "Show all folders and files in tree apparence\n";
	_result += "type tree to show all folders and files.";
	Utils::Log(_result);
}
