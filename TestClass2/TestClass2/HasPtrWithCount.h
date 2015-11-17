#pragma once
#include<string>
class HasPtrWithCount
{
public:
	HasPtrWithCount(const std::string & = std::string());
	HasPtrWithCount(const HasPtrWithCount&);
	HasPtrWithCount& operator=(const HasPtrWithCount&);
	~HasPtrWithCount();
private:
	std::string *ps;
	int i;
	std::size_t *use;
};

