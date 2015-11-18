#pragma once
#ifndef STRVEC
#define STRVEC
#include <memory>
#include <string>
#include <map>
#include <iostream>
#include <algorithm>

//StrVec是个模仿vector但是只有string操作的容器类型
class StrVec{
public:
	StrVec() :elements(nullptr), first_free(nullptr), cap(nullptr){}
	StrVec(std::initializer_list<std::string>);
	StrVec(const StrVec&);
	StrVec& operator=(const StrVec&);

	StrVec(StrVec&&);
	StrVec& operator=(StrVec &&);
	~StrVec();

	void push_back(const std::string&);
	size_t size()const{
		return first_free - elements;
	}
	size_t capacity() const{
		return cap - elements;
	}
	std::string *begin()const{
		return elements;
	}
	std::string *end()const{
		return first_free;
	}
private:
	static std::allocator<std::string> alloc;
	void chk_n_alloc(){
		if (size() == capacity())
			reallocate();
	}
	std::pair<std::string*, std::string*> alloc_n_copy(const std::string*, const std::string*);
	void free();
	void reallocate();

	std::string *elements;
	std::string *first_free;
	std::string *cap;
};
#endif