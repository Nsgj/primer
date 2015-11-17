#include "StrBlob.h"


std::string& StrBlob::front(){
	check(0, "front on empty StrBlob");
	return data->front();
}

std::string& StrBlob::back(){
	check(0, "back on empty StrBlob");
	return data->back();
}

void StrBlob::pop_back(){
	check(0, "pop_back on empty");
	data->pop_back();
}

void StrBlob::check(size_type i, const std::string &msg)const{
	if (i >= data->size()){
		throw std::out_of_range(msg);
	}
}
long StrBlob::count(){
	return data.use_count();
}
StrBlob::StrBlob(std::initializer_list<std::string> il) :data(std::make_shared<std::vector<std::string>>(il)){}
StrBlob::StrBlob() :data(std::make_shared<std::vector<std::string>>()){}
StrBlob::~StrBlob(){}
//像值的操作
StrBlob::StrBlob(const StrBlob&sb){
	auto temp = std::make_shared<std::vector<std::string>>(*sb.data);
	data = temp;

}
StrBlob& StrBlob::operator=(const StrBlob&sb){
	//auto temp = std::make_shared<std::vector<std::string>>(*sb.data);//保存左值，防止异常
	data = std::make_shared<std::vector<std::string>>(*sb.data);//一句就可以保证安全的使用资源了，不需要先复制左值，销毁。然后再拷贝
	return *this;
}