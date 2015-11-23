#pragma once
//#include "Sales_data.h"
#include "Screen.h"
int main(){
	/*Sales_data total;
	if (read(std::cin,total)){
		Sales_data trans;
		while (read(std::cin,trans))
		{
			if (total.getIsbn() == trans.getIsbn()){
				total.combine(trans);
			}
			else
			{
				print(std::cout, total) << std::endl;
				total = trans;
			}
		}
		print(std::cout, total) << std::endl;
	}
	else
	{
		std::cerr << "NO data?!" << std::endl;
	}*/

	/*Sales_data total(std::cin);
	if (!total.getIsbn().empty()){
		std::istream &is = std::cin;;
		while (is)
		{
			Sales_data trans(is);
			if (total.getIsbn() == trans.getIsbn()){
				total.combine(trans);
			}
			else
			{
				print(std::cout, total) << std::endl;
				total = trans;
			}
		}
		print(std::cout, total) << std::endl;
	}
	else
	{
		std::cerr << "No data?!" << std::endl;
	}*/

	/*Sales_data sd1;
	Sales_data sd2("1234");
	Sales_data sd3("wewe", 2312, 2.9);
	Sales_data sd4(std::cin);*/

	Screen myscreen;
	char ch = myscreen.get();
	myscreen.get(0, 0);
}