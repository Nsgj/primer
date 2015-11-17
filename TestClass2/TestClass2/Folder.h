#pragma once
#include <set>
#include "Message.h"
class Folder
{
public:
	Folder();
	~Folder();

	void addMsg(Message*);
	void remMsg(Message*);
private:
	std::set<Message*> messages;
};

