#include <iostream>

#include "Quote.h"
#include "Bulk_quote.h"
#include "Bulk_quote_Disc.h"

using namespace std;

double print_total(ostream &os, const Quote &item, size_t n)
{
    auto ret = item.net_price(n);
    os << "isbn: " << item.isbn() << " # sold: " << n
       << " total due: " << ret << endl;
    return ret;
}

int main()
{
    Bulk_quote_Disc bq("bulk", 10.0, 3, 0.3);
    Quote q("normal", 10.0);
    Quote *qt = &bq;
    print_total(cout, *qt, 10);
    qt->debug(cout) << endl;
    return 0;
}