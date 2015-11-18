#pragma once
#include <string>
#include "Quote.h"
#include <map>
class Disc_quote:public Quote
{
public:
	Disc_quote() = default;
	Disc_quote(const std::string& book, double price, std::size_t qty, double disc) :Quote(book, price), quantity(qty), discount(disc){}
	double net_price(std::size_t)const = 0;
	std::pair<size_t, double> discount_policy()const{
		return{ quantity, discount };
	}
	~Disc_quote();
protected:
	std::size_t quantity = 0;
	double discount = 0.0;
};