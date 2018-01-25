/*
 @Date    : 2017-12-21 14:13:02
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
在此处添加文件说明
 */

#include <iostream>
#include "Sales_data.h"

using namespace std;

int main()
{
    cout << "1.default" << endl;
    Sales_data a;
    print(cout, a);
    cout << "2.offer a string" << endl;
    Sales_data b("abcdefg");
    print(cout, b);
    cout << "3.offer 3 arguments" << endl;
    Sales_data c("absddsjkhfjk", 1, 2);
    print(cout, c);
    cout << "4.cin" << endl;
    Sales_data d(cin);
    print(cout, d);
    return 0;
}

istream& read(istream& is, Sales_data& item)
{
    double p;
    is >> item.bookNo >> item.units_sold >> p;
    item.revenue = p * item.units_sold;
    return is;
}

ostream& print(ostream& os, const Sales_data& item)
{
    os << item.isbn() << " " << item.units_sold << " "
       << item.revenue << " " << endl;
    return os;
}

Sales_data add(const Sales_data& l, const Sales_data& r)
{
    Sales_data sum = l;
    sum.combine(r);
    return sum;
}
