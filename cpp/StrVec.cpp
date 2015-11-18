#include "StrVec.h"

void StrVec::push_back(const std::string& s){
	chk_n_alloc();
	alloc.construct(first_free++, s);
}
std::pair<std::string*, std::string*> StrVec::alloc_n_copy(const std::string*b, const std::string *e){//�����µ�vecʱ�����ɵĸ��ƹ���
	//pair�е�һ��ָ�����Ŀռ䣬�ڶ���ָ���ù�������������������͵����һ���ĺ���
	auto data = alloc.allocate(e - b);//data�Ǹ�pointer ָ���·���Ŀռ�

	return{ data, std::uninitialized_copy(b, e, data) };//����һ���б��ʼ����pair
}
void StrVec::free(){
	/*if (elements){
		for (auto p = first_free; p != elements;){
			alloc.destroy(--p);
		}
		alloc.deallocate(elements, cap - elements);
	}*/
	std::for_each(elements, first_free, [this](std::string& p){alloc.destroy(&p); });
	alloc.deallocate(elements, cap - elements);
}
StrVec::StrVec(const StrVec &s){
	auto newdata = alloc_n_copy(s.begin(), s.end());
	elements = newdata.first;
	first_free = cap = newdata.second;//βָ���ʹ����ָ��ָ��ͬһ��λ��
}

StrVec::StrVec(std::initializer_list<std::string> li){
	/*std::string temp("");
	for (auto f : li){
		temp += f;
	}
	elements = new std::string(temp);
	first_free = cap = elements + temp.size();*/
	auto pair = alloc_n_copy(li.begin(), li.end());
	elements = pair.first;
	first_free = cap = pair.second;
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

StrVec::StrVec(StrVec&& sv) noexcept :elements(sv.elements),first_free(sv.first_free),cap(sv.cap){
	sv.elements = sv.first_free = sv.cap = nullptr;
}
StrVec& StrVec::operator=(StrVec &&sv){
	if (&sv != this){
		free();
		elements = sv.elements;
		first_free = sv.first_free;
		cap = sv.cap;

		sv.elements = sv.cap = sv.first_free = nullptr;
	}
	return *this;
}
std::allocator<std::string> StrVec::alloc;