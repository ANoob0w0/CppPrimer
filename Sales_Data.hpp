#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <iostream>
#include <string>
#include <vector>

class Sales_Data
{
private:
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;

public:
    Sales_Data() = default;
    explicit Sales_Data(std::istream& is){read(is);}
    explicit Sales_Data(const std::string& n):bookNo(n){}
    Sales_Data(const std::string &n, const unsigned &s, const double &price) : bookNo(n), units_sold(s), revenue(price * s) { std::cout << "normal" << std::endl; }
    // //delegating constructor
    // Sales_Data() : Sales_Data("", 0, 0) { std::cout << "dc1" << std::endl; }
    // Sales_Data(const std::string &n) : Sales_Data() { std::cout << "dc2" << std::endl; }

    ~Sales_Data(){};
    std::string isbn() const;
    double avg_price() const;
    Sales_Data &combine(const Sales_Data &);
    std::istream &read(std::istream &);
    std::ostream &print(std::ostream &);
};
Sales_Data add(const Sales_Data &, const Sales_Data &);

// Sales_Data::Sales_Data(/* args */)
// {
// }

// Sales_Data::~Sales_Data()
// {
// }

std::string Sales_Data::isbn() const { return this->bookNo; }

inline double Sales_Data::avg_price() const
{
    if (units_sold)
        return revenue / units_sold;
    else
        return 0;
}

Sales_Data &Sales_Data::combine(const Sales_Data &rhs)
{
    revenue += rhs.revenue;
    units_sold += rhs.units_sold;
    return *this;
}

std::istream &Sales_Data::read(std::istream &is)
{
    double price = 0.0;
    is >> bookNo >> units_sold >> price;
    revenue = units_sold * price;
    return is;
}

std::ostream &Sales_Data::print(std::ostream &os)
{
    os << isbn() << " " << units_sold << " " << revenue << " " << avg_price();
    return os;
}

Sales_Data add(const Sales_Data &lhs, const Sales_Data &rhs)
{
    Sales_Data sum = lhs;
    sum.combine(rhs);
    return sum;
}

#endif