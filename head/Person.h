#pragma once
#include <string>
#include <iostream>
class Person
{
public:
	std::string getName()const;
	std::string getAddress()const;
	Person();
	Person(std::string Name, std::string Address) :name(Name), address(Address){}
	~Person();
private:
	std::string name;
	std::string address;
};

std::ostream &print(std::ostream &out, const Person& sd){
	out << sd.getName() << " " << sd.getAddress();
	return out;
}
