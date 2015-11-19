#pragma once
#include <memory>
#include <set>
#include <iostream>
#include "Quote.h"
class Basket
{
public:
	double total_receipt(std::ostream &os) const;
	Basket();
	~Basket();
private:
	static bool compare(const std::shared_ptr<Quote> &lhs, const std::shared_ptr<Quote> &rhs){
		return lhs->isbn() < rhs->isbn();	
	}
	
	std::multiset<std::shared_ptr<Quote>, decltype(compare)*> items{ compare };
};

