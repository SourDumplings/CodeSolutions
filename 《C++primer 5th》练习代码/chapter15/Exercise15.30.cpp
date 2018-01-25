/*
 @Date    : 2018-01-09 21:34:20
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p634
 */

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <set>

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
    virtual Quote* clone() const & { return new Quote(*this); }
    virtual Quote* clone() && { return new Quote(std::move(*this)); }
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
    Bulk_quote* clone() const & { return new Bulk_quote(*this); }
    Bulk_quote* clone() && { return new Bulk_quote(std::move(*this)); }
    double net_price(size_t cnt) const
    {
        if (cnt > quantity)
            return cnt * price * (1 - discount);
        else
            return cnt * price;
    }
};

class Basket
{
private:
    static bool compare(const shared_ptr<Quote> &lhs, const shared_ptr<Quote> &rhs)
    { return lhs->isbn() < rhs->isbn(); }
    multiset<shared_ptr<Quote>, decltype(compare)*> items{compare};
public:
    double total_receipt(size_t);
    void add_item(const Quote &sale)
    { items.insert(shared_ptr<Quote>(sale.clone())); }
    void add_item(Quote &&sale)
    { items.insert(shared_ptr<Quote>(std::move(sale).clone())); }
};

inline double Basket::total_receipt(size_t n)
{
    double sum = 0;
    for (auto &q : items)
        sum += q->net_price(n);
    return sum;
}



int main(int argc, char const *argv[])
{
    Basket bq;
    Bulk_quote bq1("book1", 100, 10, 0.1), bq2("book1", 200, 5, 0.5), bq3("book2", 300, 5, 0.5);
    bq.add_item(bq1);
    bq.add_item(bq2);
    bq.add_item(bq3);
    double sum = 0.0;

    cout << "the sum of charge of books is: " <<
    bq1.net_price(50) + bq2.net_price(50) + bq3.net_price(50)<< endl;

    cout << "the sum of charge of books in bq is: ";
    sum = bq.total_receipt(50);
    cout << sum << endl;
    return 0;
}
