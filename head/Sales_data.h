#pragma once
#ifndef SALES_DATA_H

#define SALES_DATA_H

#include <string>
#include <iostream>

class Sales_data
{
	friend std::istream &read(std::istream &, Sales_data& );
	friend Sales_data add(const Sales_data &, const Sales_data &);
	friend std::ostream &print(std::ostream &, const Sales_data&);
public:
	std::string getIsbn() const;
	Sales_data& combine(const Sales_data&);
	

	Sales_data()=default;
	Sales_data(const std::string &s) :bookNo(s){}
	Sales_data(const std::string &s, unsigned n, double p) :bookNo(s), units_sold(n), revenue(p*n){}
	Sales_data(std::istream&in){
		read(in, *this);
	}
	~Sales_data();
private:
	double avg_price()const;

	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};
std::ostream &print(std::ostream &, const Sales_data&);
Sales_data add(const Sales_data &, const Sales_data &);
std::istream &read(std::istream &, Sales_data&);
#endif
