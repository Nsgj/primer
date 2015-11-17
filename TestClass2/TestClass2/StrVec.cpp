#include "StrVec.h"
void StrVec::push_back(const std::string& s){
	chk_n_alloc();
	alloc.construct(first_free++, s);
}
std::pair<std::string*, std::string*> StrVec::alloc_n_copy(const std::string*b, const std::string *e){//创建新的vec时，将旧的复制过来
	//pair中第一个指向分配的空间，第二个指向用过（用来拷贝）后的类型的最后一个的后面
	auto data = alloc.allocate(e - b);//data是个pointer 指向新分配的空间

	return{ data, std::uninitialized_copy(b, e, data) };//返回一个列表初始化的pair
}
void StrVec::free(){
	if (elements){
		for (auto p = first_free; p != elements;){
			alloc.destroy(--p);
		}
		alloc.deallocate(elements, cap - elements);
	}
}
StrVec::StrVec(const StrVec &s){
	auto newdata = alloc_n_copy(s.begin(), s.end());
	elements = newdata.first;
	first_free = cap = newdata.second;//尾指针和使用量指针指向同一个位置
}
StrVec::~StrVec(){
	free();
}
StrVec &StrVec::operator=(const StrVec &rhs){
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}
void StrVec::reallocate(){
	auto newcapacity = size() ? 2 * size() : 1;
	auto newdata = alloc.allocate(newcapacity);

	auto dest = newdata;
	auto elem = elements;
	for (size_t i = 0; i != size(); ++i){
		alloc.construct(dest++, std::move(*elem++));
	}
	free();
	elements = newdata;

}
std::allocator<std::string> StrVec::alloc;