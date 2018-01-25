/*
 @Date    : 2018-01-08 18:57:45
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p611
 */

#ifndef MY_QUOTE_H
#define MY_QUOTE_H

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
    string& isbn() { return bookNo; }
    const string& isbn() const { return bookNo; }
};

double print_total(ostream &os, const Quote &item, size_t n)
{
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret << endl;
    return ret;
}

class Disc_quote: public Quote
{
protected:
    size_t quantity = 0;
    double discount = 0.0;
public:
    Disc_quote() = default;
    Disc_quote(const string &book, double price, size_t qty, double disc):
        Quote(book, price), quantity(qty), discount(disc) {}
    double net_price(size_t) const = 0;
};

class Bulk_quote: public Disc_quote
{
public:
    Bulk_quote() = default;
    Bulk_quote(const string &book, double price, size_t qty, double disc):
        Disc_quote(book, price, qty, disc) {}
    double net_price(size_t) const override;
};

double Bulk_quote::net_price(size_t cnt) const
{
    if (cnt >= quantity)
        return cnt * (1 - discount) * price;
    else
        return cnt * price;
}

class Limited_quote: public Disc_quote
{
public:
    Limited_quote() = default;
    Limited_quote(const string &book, double price, size_t qty, double disc):
        Disc_quote(book, price, qty, disc) {}
    double net_price(size_t) const override;
};

double Limited_quote::net_price(size_t cnt) const
{
    if (cnt <= quantity)
        return cnt * (1 - discount) * price;
    else
        return quantity * (1 - discount) * price + (cnt - quantity) * price;
}

#endif
