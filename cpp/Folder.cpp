#include "Folder.h"



Folder::Folder()
{
}


Folder::~Folder()
{
}
void Folder::addMsg(Message*ms){
	messages.insert(ms);
}
void Folder::remMsg(Message*ms){
	messages.erase(ms);
}