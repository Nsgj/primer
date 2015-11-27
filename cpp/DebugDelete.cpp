#include <iostream>
class DebugDelete{
public:
	DebugDelete(std::ostream &s = std::cerr) :os(s){}
	template <typename T> void operator()(T *p) const{
		os << "delteing unique_ptr" << std::endl;
		delelte p;
	}
private:
	std::ostream &os;
};