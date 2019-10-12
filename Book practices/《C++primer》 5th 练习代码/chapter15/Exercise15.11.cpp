/*
 @Date    : 2018-01-08 18:05:48
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p608
 */

#include <iostream>
#include <string>

using namespace std;

class Quote
{
private:
    string bookNo;
protected:
    double price = 0.0;
public:
    Quote() = default;
    Quote(const string &book, double sales_price): bookNo(book), price(sales_price) {}
    virtual double net_price(size_t n) const { return n * price; }
    virtual ~Quote() = default;
    virtual void debug() { cout << "bookNo: " << bookNo << " price: " << price << endl; }
    string& isbn() { return bookNo; }
    const string& isbn() const { return bookNo; }
};

double print_total(ostream &os, const Quote &item, size_t n)
{
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret << endl;
    return ret;
}

class Bulk_quote: public Quote
{
private:
    size_t min_qty = 0;
    double discount = 0.0;
public:
    virtual void debug() override
    { Quote::debug(); cout << "min_qty: " << min_qty << " discount: " << discount << endl; }
    Bulk_quote() = default;
    Bulk_quote(const string &, double, size_t, double);
    double net_price(size_t) const override;
};

Bulk_quote::Bulk_quote(const string &book, double p, size_t qty, double disc):
    Quote(book, p), min_qty(qty), discount(disc) {}

double Bulk_quote::net_price(size_t cnt) const
{
    if (cnt >= min_qty)
        return cnt * (1 - discount) * price;
    else
        return cnt * price;
}

int main(int argc, char const *argv[])
{
    size_t minnum = 5;
    double price = 10, discount = 0.1;
    string isbn("mybook");
    Quote q(isbn, price);
    Bulk_quote bq(isbn, price, minnum, discount);
    q.debug();
    bq.debug();
    return 0;
}
