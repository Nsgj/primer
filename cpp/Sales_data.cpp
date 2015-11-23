#include "Sales_data.h"

std::string Sales_data::getIsbn() const{
	return bookNo;
}
Sales_data& Sales_data::combine(const Sales_data& sd){
	units_sold += sd.units_sold;
	revenue += sd.revenue;
	return *this;
}
double Sales_data::avg_price()const{
	if (units_sold){
		return revenue / units_sold;
	}
	else
	{
		return 0;
	}
}
Sales_data::~Sales_data()
{
}

Sales_data add(const Sales_data &a, const Sales_data &b){
	Sales_data sum = a;
	sum.combine(b);
	return sum;
}
std::istream &read(std::istream &in, Sales_data& sd){
	//in >> sd.getIsbn;
	double price = 0;
	in >> sd.bookNo >> sd.units_sold >> price;
	return in;
}
std::ostream &print(std::ostream &out, const Sales_data& sd){
	out << sd.getIsbn() << " " << sd.units_sold << " " << sd.revenue << " " << sd.avg_price() << std::endl;

	return out;
}