#ifndef BULK_QUOTE_H
#define BULK_QUOTE_H

#include "Quote.h"

class Bulk_quote : public Quote
{
private:
    std::size_t min_qyt = 0;
    double discount = 0.0;
public:
    Bulk_quote() = default;
    Bulk_quote(const std::string &, const double &, std::size_t, double);
    ~Bulk_quote() = default;
    double net_price(std::size_t n) const override;
    std::ostream& debug(std::ostream& os) const override;
};

Bulk_quote::Bulk_quote(const std::string &isbn, const double &sales_price, std::size_t qty, double disc)
    : Quote(isbn, sales_price), min_qyt(qty), discount(disc){}

double Bulk_quote::net_price(std::size_t n) const {
    if(n >= min_qyt)
        return n*(1 - discount)*price;
    else
        return n*price;
}

std::ostream& Bulk_quote::debug(std::ostream& os) const{
    Quote::debug(os) << min_qyt << " " << discount << " ";
    return os;
}

#endif