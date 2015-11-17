#include"StrBlobPtr.h"

std::shared_ptr<std::vector<std::string>> StrBlobPtr::cheak(std::size_t i, const std::string& msg)const{
	auto ret = wptr.lock();
	if (!ret){
		throw std::runtime_error("unbound StrBlobPtr");
	}
	if (i >= ret->size()){
		throw std::out_of_range(msg);
	}
	return ret;
}
std::string& StrBlobPtr::deref()const{
	auto p = cheak(curr, "dereference past end");
	return (*p)[curr];
}
StrBlobPtr& StrBlobPtr::incr(){
	cheak(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
}
StrBlobPtr::StrBlobPtr() : curr(0){}
StrBlobPtr::StrBlobPtr(StrBlob &a, size_t sz) : wptr(a.data), curr(sz){}
StrBlobPtr::~StrBlobPtr(){}
long StrBlobPtr::count(){
	return wptr.use_count();
}