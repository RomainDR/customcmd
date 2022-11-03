#pragma once
#include <string>
#include <iostream>
#include <vector>
class Utils

{
public:
	static std::string ToLower(std::string _str);

	static void ChangeTitle(std::string _name);

	template<typename T>
	static T UserChoice(std::string _msg);

	static void Log(std::string _msg);

	static std::string GetHelpShortcut(std::string _str);

	static std::vector<std::string> Split(const std::string& _choice, const char& _c);

	static std::string FileWithoutExtension(std::string& _args);

	static void Replace(std::string& _str, const char& _old, const char& _newValue);

	static int CountChar(const std::string& _path, const char& _c);

};

template<typename T>
T Utils::UserChoice(std::string _msg)
{
	T _input;
	if(_msg != "") std::cout << _msg;
	std::getline(std::cin, _input);
	return _input;
}
