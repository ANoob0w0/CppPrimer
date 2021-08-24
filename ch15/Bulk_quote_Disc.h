#ifndef BULK_QUOTE_DISC_H
#define BULK_QUOTE_DISC_H

#include "Disc_quote.h"

class Bulk_quote_Disc : public Disc_quote
{
public:
    Bulk_quote_Disc() = default;
    Bulk_quote_Disc(const std::string &, const double &, std::size_t, double);
    ~Bulk_quote_Disc() = default;
    double net_price(std::size_t n) const override;
    std::ostream& debug(std::ostream& os) const override;
};

Bulk_quote_Disc::Bulk_quote_Disc(const std::string &isbn, const double &sales_price, std::size_t qty, double disc)
    : Disc_quote(isbn, sales_price, qty, disc){}

double Bulk_quote_Disc::net_price(std::size_t n) const {
    if(n < quantity)
        return n*(1 - discount)*price;
    else
        return n*price;
}

std::ostream& Bulk_quote_Disc::debug(std::ostream& os) const{
    Quote::debug(os) << quantity << " " << discount << " ";
    return os;
}

#endif