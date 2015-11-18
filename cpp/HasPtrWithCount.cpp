#include "HasPtrWithCount.h"


HasPtrWithCount::HasPtrWithCount(const std::string &s):ps(new std::string(s)),i(0),use(new size_t(1)){
	
}
HasPtrWithCount::HasPtrWithCount(const HasPtrWithCount&hpwc) : ps(hpwc.ps), i(hpwc.i){
	++*hpwc.use;
	use = hpwc.use;
}
HasPtrWithCount& HasPtrWithCount::operator=(const HasPtrWithCount&hpwc){
	++*hpwc.use;
	if (--*use == 0){
		delete ps;
		delete use;
	}
	ps = hpwc.ps;
	i = hpwc.i;
	use = hpwc.use;
	return *this;
	/*auto temp (hpwc);
	delete ps;
	--*use;
	++*temp.use;
	ps = temp.ps;*/
}

HasPtrWithCount::~HasPtrWithCount()
{
	if (--*use == 0){
		delete ps;
		delete use;
	}
}
