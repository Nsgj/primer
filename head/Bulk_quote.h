#include "Disc_quote.h"
class Bulk_quote :public Disc_quote{
public:
	Bulk_quote() = default;
	Bulk_quote(const std::string& book, double p, std::size_t qty, double disc) :Disc_quote(book,p,qty,disc){}
	double net_price(std::size_t) const override;
private:
	std::size_t min_qty = 0;
	double discount = 0.0;
};