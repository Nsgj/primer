#include "TBlob.h"
template <typename T>
void TBlob<T>::cheak(size_type i, const std::string &msg)const{
	if (i >= data->size()){
		throw std::out_of_range(msg);
	}
}
template <typename T>
T& TBlob<T>::back(){
	cheak(0, "back on empty blob");
	return data->back();
}
template <typename T>
T& TBlob::operator[](size_type i){
	check(i, "subscript out of range");
	return (*data)[i];
}
template <typename T>
void TBlob<T>::pop_back(){
	check(0, "pop_back on empty Blob");
	data->pop_back();
}
template <typename T>
TBlob<T>::TBlob() :data(std::make_shared<std::vector<T>>()){}

template <typename T>
TBlob<T>::TBlob(std::initialier_list<T> il) : data(std::make_shared<std::vector<T>>(il)){}