#pragma once
#include <string>
class HasPtr
{
	
public:
	friend void swap(HasPtr&, HasPtr&);
	friend bool operator<(const HasPtr&, const HasPtr&);
	HasPtr(const std::string & = std::string());
	/*HasPtr& operator=(const HasPtr&);
	*/
	HasPtr(std::string,int);
	HasPtr(const HasPtr&);
	/*HasPtr& operator=(const HasPtr&);*/
	HasPtr& operator=(HasPtr hp);
	//bool operator<(HasPtr &hp);
	~HasPtr();
private:
	std::string *ps;
	int i;
};

