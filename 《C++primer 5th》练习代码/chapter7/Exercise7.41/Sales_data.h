/*
 @Date    : 2017-12-21 14:04:15
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p292
 */

#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <string>
#include <iostream>

using namespace std;

class Sales_data;
istream& read(istream&, Sales_data&);

class Sales_data
{
    friend istream& read(istream&, Sales_data&);
    friend ostream& print(ostream&, const Sales_data&);
    friend Sales_data add(const Sales_data&, const Sales_data&);
public:
    Sales_data() : Sales_data("", 0, 0) { cout << "Sales_data() called" << endl;}
    Sales_data(const string &s);
    Sales_data(const string &s, unsigned n, double p) :
        bookNo(s), units_sold(n), revenue(n * p)
        {
            cout << "Sales_data(const string &s, unsigned n, double p) called" << endl;
        }
    Sales_data(istream &is) : Sales_data()
    {
        read(is, *this);
    }
    string isbn() const;
    inline double avg_price() const;
private:
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
    Sales_data& combine(const Sales_data&);
};

istream& read(istream&, Sales_data&);
ostream& print(ostream&, const Sales_data&);
Sales_data add(const Sales_data&, const Sales_data&);

inline Sales_data::Sales_data(const string &s) : Sales_data::Sales_data(s, 0, 0)
{
    cout << "Sales_data(const string &s) called" << endl;
}

inline string Sales_data::isbn(void) const
{
    return bookNo;
}

inline Sales_data& Sales_data::combine(const Sales_data &rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

inline double Sales_data::avg_price() const
{
    return revenue / units_sold;
}

#endif
