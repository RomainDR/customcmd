#include "PathManager.h"
#include "shlobj_core.h"
#include <fstream>
#include "Utils.h"
void PathManager::SetPath(std::string& _path)
{
    path = _path;
}

std::string PathManager::GetPathUser()
{Utils::Replace(path, '\\', '/');
	TCHAR szPath[MAX_PATH];
	HRESULT _result = SHGetFolderPath(NULL, CSIDL_PROFILE, NULL, 0, szPath);
	char* _user = new char[MAX_PATH];
	int _save = 0;
	for (int i = 0; i < MAX_PATH; i++)
	{
		if (szPath[i] == 0)
			break;
		_user[i] = szPath[i];
		_save = i;
	}
	_user[_save + 1] = '\0';
	std::string user = _user;
	path = user;
	Utils::Replace(path, '\\', '/');
	return path;
}

std::string PathManager::GetPath()
{
	Utils::Replace(path, '\\', '/');
	if (path == "")
		return GetPathUser();
    return path;
}

std::string PathManager::GetPath(std::string _completPath)
{
	return _completPath.substr(0, _completPath.find_last_of('/'));
}

bool PathManager::IsFullPath(std::string _completePath)
{
	bool contains = false;
	size_t _size = _completePath.size();
	for (int i = 0; i < _size && !contains; i++)
	{
		contains = _completePath[i] == '/' || _completePath[i] == '\\';
	}
	return contains;
}

bool PathManager::Exist(std::string _file, std::string _path) const
{
	std::string path = _path == "" ? this->path : _path;
	std::ifstream _stream = std::ifstream(path + "/" + _file + ".txt");
	const bool _exist = _stream.good();
	_stream.close();
	return _exist;
}

bool PathManager::ExistPath(std::string _path) const
{
	struct stat _info { };
	if (stat(_path.c_str(), &_info) != 0) return false;
	return _info.st_mode & S_IFDIR;
}

bool PathManager::StartInDrivers(std::string _args)
{
	return _args[1] == ':';
}
