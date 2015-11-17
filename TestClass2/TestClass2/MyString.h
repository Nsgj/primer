#pragma once
#include <memory>
#include <map>
class MyString
{
public:
	friend void swap(MyString&, MyString&);
	MyString();
	MyString(char*);
	MyString(const MyString&);
	MyString& operator=(MyString);

	MyString(MyString&&);
	MyString& operator=(MyString&&);
	~MyString();
private:
	void chk_n_alloc();
	void free();
	std::pair<char*, char*> alloc_n_copy(const char*, const char*);

	static std::allocator<char> allo;
	char* elements;
	char* first_free;
};

