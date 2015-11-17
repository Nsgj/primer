#pragma once
#ifndef STRBLOB
#define STRBLOB
//#ifndef STRBLOBPTR
//#include "StrBlobPtr.h"
//#endif
#include <memory>
#include <vector>
#include <string>

class StrBlob//管理Str的类
{
	friend class StrBlobPtr;
public:
	typedef std::vector<std::string>::size_type size_type;

	StrBlob();
	StrBlob(std::initializer_list<std::string> );

	//像值的操作
	StrBlob(const StrBlob&);
	StrBlob& operator=(const StrBlob&);

	size_type size() const{ return data->size(); }
	bool empty(){ return data->empty(); }

	void push_back(const std::string&t){ data->push_back(t); }
	void pop_back();

	std::string& front();
	std::string& back();

	long count();

	~StrBlob();
private:
	std::shared_ptr<std::vector<std::string>> data;
	void check(size_type i, const std::string &msg)const;
};
#endif 
