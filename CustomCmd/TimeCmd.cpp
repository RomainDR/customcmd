#include "TimeCmd.h"
#include <ctime>
#include "Utils.h"
#include <format>

#pragma warning(disable : 4996)

#pragma region constructor
TimeCmd::TimeCmd(std::string _shortcut, std::string _description)
{
	shortcut = _shortcut;
	description = _description;
	lines.push_back("display the current time of system");
}
#pragma endregion constructor

#pragma region methods

std::string TimeCmd::GetShortcut()
{
	return shortcut;
}

std::string TimeCmd::GetDescription()
{
	return description;
}

void TimeCmd::Execute()
{
	const time_t _now = time(nullptr);
	const std::tm _tm = *localtime(&_now);
	std::cout << std::format("Current time: {:02}/{:02}/{:02} {:02}:{:02}:{:02}", _tm.tm_mday, _tm.tm_mon + 1, _tm.tm_year + 1900, _tm.tm_hour, _tm.tm_min, _tm.tm_sec) << std::endl;
}
void TimeCmd::GetHelp()
{
	std::string _str = "";
	size_t _size = lines.size();
	for (int i = 0; i < _size; i++)
	{
		_str.append(lines[i] + "\n");
	}
	Utils::Log(_str);
}
void TimeCmd::Execute(std::string _args)
{
	Utils::Log(description);
}
#pragma endregion methods