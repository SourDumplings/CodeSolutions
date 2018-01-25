/*
 @Date    : 2018-01-09 17:05:32
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p628
输出结果为：
Quote constructor is running
Quote constructor is running
Bulk_quote constructor is running
        Using operator <<(ostream&, Quote&);

        Using operator<<(ostream&, Bulk_quote&);

Bulk_quote destructor is running
Quote destructor is running
Quote destructor is running
说明了子类的析构会调用父类的析构函数析构继承自父类的成员
 */

#include <iostream>
#include <string>

using namespace std;

class Quote
{
    friend ostream& operator<<(ostream&, Quote&);
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

ostream& operator<<(ostream &os, Quote &q)
{
    os << "\tUsing operator <<(ostream&, Quote&);" << endl;
    return os;
}

class Bulk_quote: public Quote
{
public:
    Bulk_quote(const string &book = "", double sales_price = 0.0, size_t qty = 0,
        double disc = 0.0):
    Quote(book, sales_price), min_qty(qty), discount(disc)
    {
        cout << "Bulk_quote constructor is running" << endl;
    }
    double net_price(size_t cnt) const
    {
        if (cnt > min_qty)
            return cnt * (1 - discount) * price;
        else
            return cnt * price;
    }
    ~Bulk_quote()
    {
        cout << "Bulk_quote destructor is running" << endl;
    }
private:
    size_t min_qty;
    double discount;
};

ostream& operator<<(ostream &os, Bulk_quote &bq)
{
    os << "\tUsing operator<<(ostream&, Bulk_quote&);" << endl;
    return os;
}

int main(int argc, char const *argv[])
{
    Quote base("C++ Primer", 128.0);
    Bulk_quote bulk("Core Python Programming", 89, 5, 0.19);
    cout << base << endl;
    cout << bulk << endl;
    return 0;
}
