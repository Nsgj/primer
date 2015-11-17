#pragma once
#ifndef STRBLOBPTR
#define STRBLOBPTR
//#ifndef STRBLOB
//#include "StrBlob.h"
//#endif
#include "StrBlob.h"
#include <memory>
#include <vector>
#include <string>
class StrBlobPtr
{
public:
	StrBlobPtr();
	StrBlobPtr(StrBlob&, size_t = 0);

	std::string& deref()const;
	StrBlobPtr& incr();
	~StrBlobPtr();

	long count();

private:
	std::shared_ptr<std::vector<std::string>> cheak(std::size_t, const std::string&) const;
	std::weak_ptr<std::vector<std::string>> wptr;
	std::size_t curr;
};
#endif
