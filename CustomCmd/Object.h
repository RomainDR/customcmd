#pragma once
#include <string>
class Object
{
public:
	Object() = default;
	Object(Object& _copy) = default;
	virtual ~Object() = default;

public:
	virtual std::string ToString() const;
};

