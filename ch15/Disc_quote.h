#ifndef DISC_QUOTE_H
#define DISC_QUOTE_H

#include "Quote.h"

class Disc_quote : public Quote
{
protected:
    std::size_t quantity = 0;
    double discount = 0.0;

public:
    Disc_quote(/* args */) = default;
    Disc_quote(const std::string &isbn, const double price, const std::size_t qty, const double &disc)
        : Quote(isbn, price), quantity(qty), discount(disc) {}
    ~Disc_quote() = default;
    double net_price(std::size_t) const = 0;
};
#endif