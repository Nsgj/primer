#include "Message.h"

Message::Message(const std::string &str):contents(str) {

}

Message::Message(const Message&)
{
}

Message::Message(const Message&m) :contents(m.contents), folders(m.folders) {
	add_to_Folders(m);
}

Message::~Message()
{
	remove_from_Folder();
}

void Message::save(Folder& f) {
	folders.insert(&f);
	f.addMsg(this);
}

void Message::remove(Folder& f) {
	folders.erase(&f);
	f.remMsg(this);
}

void Message::add_to_Folders(const Message &m) {
	for (auto f : m.folders) {
		f->addMsg(this);
	}
}
void Message::remove_from_Folder() {
	for (auto f : folders) {
		f->remMsg(this);
	}
}

Message& Message::operator=(const Message&rhs) {
	remove_from_Folder();
	contents = rhs.contents;
	folders = rhs.folders;
	add_to_Folders(rhs);
	return *this;
}
Message::Message(Message&& me):folders(me.folders),contents(me.contents){
	me.folders.clear();
	me.contents.clear();
}
Message& Message::operator = (Message&& me){
	if (&me != this){
		folders.clear();
		contents.clear();
		folders = me.folders;
		contents = me.contents;
	}
	return *this;
}
void swap(Message &lhs, Message&rhs) {
	using std::swap;

	for (auto f : lhs.folders) {
		f->remMsg(&lhs);
	}
	for (auto f : rhs.folders) {
		f->remMsg(&rhs);
	}

	swap(lhs.folders, rhs.folders);
	swap(lhs.contents, rhs.contents);

	for (auto f : lhs.folders) {
		f->addMsg(&lhs);
	}
	for (auto f : rhs.folders) {
		f->addMsg(&rhs);
	}
}

void Message::addFolder(Folder*f){
	folders.insert(f);
}
void Message::remFolders(Folder*f){
	folders.erase(f);
}
