#pragma once
#include <string>
class Employee
{
public:
	Employee() = default;
	Employee(std::string &);
	~Employee();
private:
	std::string name;
	
};

