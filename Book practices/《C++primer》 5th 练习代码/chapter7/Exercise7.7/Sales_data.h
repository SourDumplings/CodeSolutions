/*
 @Date    : 2017-12-14 19:42:09
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p262
 */

#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <string>

using namespace std;

struct Sales_data
{
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
    string isbn() const;
    Sales_data& combine(const Sales_data&);
};

string Sales_data :: isbn(void) const
{
    return bookNo;
}

Sales_data& Sales_data :: combine(const Sales_data& rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

istream& read(istream&, Sales_data&);

ostream& print(ostream&, const Sales_data&);

Sales_data add(const Sales_data&, const Sales_data&);

#endif
