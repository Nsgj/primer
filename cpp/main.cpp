#include <iostream>
#include "Quote.h"
#include "Bulk_quote.h"
#include <iostream>

double print_total(std::ostream &, const Quote &, size_t);
int main(){
	/*Quote basic;
	Bulk_quote bulk;

	Quote &P = basic;
	Quote item;
	Bulk_quote bulk;
	Quote *p = &item;
	p = &bulk;
	Quote &r = bulk;*///引用和指针都可以使用这种多态性

	/*print_total(std::cout, basic, 20);
	print_total(std::cout, bulk, 20);*/
	Quote base("0-201-82470-1", 50);
	print_total(std::cout, base, 10);
	Bulk_quote derived("0-201-82470-1", 50, 5, .19);
	print_total(std::cout, derived, 10);
}

double print_total(std::ostream &os, const Quote &item, size_t n){
	double ret = item.net_price(n);
	os << "ISBN:" << item.isbn() << "# sold:" << n << "total due:" << ret << std::endl;
	return ret;
}