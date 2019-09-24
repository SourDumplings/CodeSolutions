/*
 @Date    : 2018-01-09 20:30:16
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p631
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Quote
{
public:
    Quote() = default;
    Quote(const string &book = "", double sales_price = 0.0):
        bookNo(book), price(sales_price) {}
    string isbn() const { return bookNo; }
    virtual double net_price(size_t n) const { return n * price; }
    virtual void debug() { cout << "bookNo = " << bookNo << " price = " << price << endl; }
    virtual ~Quote() {}
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

int main(int argc, char const *argv[])
{
    vector<Quote> vq;
    Bulk_quote bq1("book", 100, 10, 0.1), bq2("book", 200, 5, 0.5);
    vq.push_back(bq1);
    vq.push_back(bq2);
    double sum = 0.0;
    cout << "the sum of charge of books is: " << bq1.net_price(50) + bq2.net_price(50) << endl;
    cout << "the sum of charge of books in vq is: ";
    for (auto &q : vq)
    {
        sum += q.net_price(50);
    }
    cout << sum << endl;
    return 0;
}
