#include "HasPtr.h"

HasPtr::HasPtr(const std::string &s) :ps(new std::string(s)), i(0){}

//HasPtr& HasPtr::operator=(const std::string& s){
//	*ps = s;
//	return *this;
//}
HasPtr::HasPtr(const HasPtr&hp):i(hp.i){
	ps = new std::string(*hp.ps);
}
HasPtr::~HasPtr(){
	delete ps;
}
//HasPtr& HasPtr::operator=(const HasPtr&hp){
//	std::string *newPtr = new std::string(*hp.ps);//不和hp共享资源，保证操作自身时也是安全的
//	delete ps;
//	ps = newPtr;
//	i = hp.i;
//	return  *this;
//}
HasPtr& HasPtr::operator=(HasPtr hp){
	using std::swap;
	swap(*this, hp);
	return *this;
}
HasPtr::HasPtr(std::string s,int u):i(u){
	ps = new std::string(s);
}
bool operator<(const HasPtr &lhs,const HasPtr &rhs){
	return lhs.i - rhs.i;
}
inline void swap(HasPtr&lhs, HasPtr&rhs){
	using std::swap;
	swap(lhs.ps, rhs.ps);
	swap(lhs.i, rhs.i);
	printf("HP's swap()");
}