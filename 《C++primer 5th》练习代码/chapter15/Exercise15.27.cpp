/*
 @Date    : 2018-01-09 19:42:35
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p629
 */

#include <iostream>
#include <string>

using namespace std;

class Quote
{
public:
    Quote() = default;
    Quote(const string &book = "", double sales_price = 0.0):
        bookNo(book), price(sales_price)
    {
        cout << "Quote constructor is running" << endl;
    }
    string isbn() const { return bookNo; }
    virtual double net_price(size_t n) const { return n * price; }
    virtual void debug() { cout << "bookNo = " << bookNo << " price = " << price << endl; }
    virtual ~Quote() { cout << "Quote destructor is running" << endl; }
private:
    string bookNo;
protected:
    double price = 0.0;
};

class Disc_quote: public Quote
{
public:
    Disc_quote(const string &book = "", double sales_price = 0.0, size_t qty = 0, double disc = 0.0):
    Quote(book, sales_price), quantity(qty), discount(disc) {}
    double net_price(size_t cnt) const = 0;
protected:
    size_t quantity;
    double discount;
};

class Bulk_quote: public Disc_quote
{
public:
    using Disc_quote::Disc_quote;
    double net_price(size_t cnt) const
    {
        if (cnt > quantity)
            return cnt * price * (1 - discount);
        else
            return cnt * price;
    }
};
