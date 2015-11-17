#pragma once
#include <string>
#include <set>
#include "Folder.h"
class Message
{
	friend class Folder;
	friend void swap(Message &, Message&);
public:
	explicit Message(const std::string & = "");
	Message(const Message&);
	Message& operator=(const Message&);
	~Message();
	void save(Folder&);
	void remove(Folder&);
private:
	std::string contents;
	std::set<Folder*> folders;

	void add_to_Folders(const Message&);
	void remove_from_Folder();
};

