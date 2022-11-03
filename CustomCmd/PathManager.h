#pragma once
#include <string>
class PathManager
{
private:
	static inline PathManager* instance = nullptr;
	std::string path = "";

public:
	PathManager() = default;
	static PathManager* Instance()
	{
		if (instance == nullptr)
			instance = new PathManager();
		return instance;
	}

public:
	void SetPath(std::string& _path);
	std::string GetPathUser();
	std::string GetPath();
	std::string GetPath(std::string _completPath);
	bool IsFullPath(std::string _completePath);
	bool Exist(std::string _file, std::string _path = "") const;
	bool ExistPath(std::string _path) const;
	bool StartInDrivers(std::string _args);
};

