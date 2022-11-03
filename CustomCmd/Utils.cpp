#include "Utils.h"
#include <Windows.h>
#include <algorithm>
std::string Utils::ToLower(std::string _str)
{
	std::string str = "";
	for (char _char : _str)
	{
		str.push_back(std::tolower(_char));
	}
	return str;

}

void Utils::ChangeTitle(std::string _name)
{
	SetConsoleTitleA(_name.c_str());
}

void Utils::Log(std::string _msg)
{
	if (_msg != "") std::cout << _msg << std::endl;
}


std::string Utils::GetHelpShortcut(std::string _str)
{
	size_t _size = _str.size();
	int _posSpace = 0;
	for (int i = 0; i < _size; i++)
	{
		if (_str[i] == 32) {
			_posSpace = i;
			break;
		}
	}
	return _str.substr(_posSpace + 1, _str.npos);
}

std::vector<std::string> Utils::Split(const std::string& _choice, const char& _c)
{
	std::vector<std::string> args = std::vector<std::string>();
	size_t _size = _choice.size();
	int _posSpace = 0;
	for (int i = 0; i < _size; i++)
	{
		if (_choice[i] == (int)_c)
		{
			_posSpace = i;			
			args.push_back(_choice.substr(0, i));
			break;
		}
	}
	args.push_back(_choice.substr(_posSpace == 0 ? _posSpace : _posSpace +1, _choice.npos));
	return args;

}

std::string Utils::FileWithoutExtension(std::string& _args)
{
	return _args.substr(0, _args.find_last_of('.'));
}

void Utils::Replace(std::string& _str, const char& _old, const char& _newValue)
{
	std::ranges::replace(_str, _old, _newValue);
}

int Utils::CountChar(const std::string& _path, const char& _c)
{
	size_t _size = _path.size();
	int number = 0;
	for (int i = 0; i < _size; i++)
		number += _path[i] == _c;
	return number;
}

