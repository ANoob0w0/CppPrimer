#ifndef QUOTE_H
#define QUOTE_H

#include <string>
#include <iostream>

class Quote
{
private:
    std::string bookNo;

protected:
    double price = 0.0;

public:
    Quote() = default;
    Quote(const std::string &isbn, const double &sales_price)
        : bookNo(isbn), price(sales_price) {}
    virtual ~Quote() = default;
    std::string isbn() const { return bookNo; }
    virtual double net_price(std::size_t n) const { return price * n; }
    virtual std::ostream& debug(std::ostream &os) const;
};

std::ostream& Quote::debug(std::ostream &os) const
{
    os << bookNo << " " << price << " ";
    return os;
}

#endif