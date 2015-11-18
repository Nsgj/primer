#include "MyString.h"


MyString::MyString() :elements(nullptr), first_free(nullptr)
{
}
MyString::MyString(char* c){
	auto temp = c;
	while (temp++);
	auto pair = alloc_n_copy(c, temp);
	elements = pair.first;
	first_free = pair.second;
}
MyString::MyString(const MyString& s){
	printf("call MyString&");
	auto newdata = allo.allocate(s.first_free - s.elements);
	first_free = std::uninitialized_copy(s.elements, s.first_free, newdata);
	elements = newdata;
}
MyString& MyString::operator = (MyString s){
	printf("call operator =");
	swap(*this, s);
	return *this;
	
}

void MyString::free(){
	auto temp = first_free;
	for (;--temp;){
		allo.destroy(temp);
	}
	allo.deallocate(elements, first_free-elements);
}
MyString::~MyString()
{
	free();
}
std::pair<char*, char*> MyString::alloc_n_copy(const char*b, const char*e){
	auto data = allo.allocate(e - b);
	return{ data, std::uninitialized_copy(b, e, data) };
}

void swap(MyString& d, MyString& e){
	using std::swap;
	swap(d.elements, e.elements);
	swap(d.first_free, e.first_free);
}

MyString::MyString(MyString&& ms) :elements(ms.elements), first_free(ms.first_free){
	ms.elements = ms.first_free = nullptr;
}
MyString& MyString::operator = (MyString&& ms){
	if (&ms != this){
		free();
		elements = ms.elements;
		first_free = ms.first_free;

		ms.elements = ms.first_free = nullptr;
	}
}
std::allocator<char> MyString::allo;